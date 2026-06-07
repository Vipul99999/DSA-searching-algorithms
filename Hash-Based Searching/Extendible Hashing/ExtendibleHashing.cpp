/*
    ExtendibleHashing.cpp
    Modern C++20

    Features:
    - Global Depth
    - Local Depth
    - Directory
    - Bucket Splitting
    - Directory Doubling
    - Insert
    - Search
    - Delete
    - Display

    Compile:
    g++ -std=c++20 ExtendibleHashing.cpp -o ExtendibleHashing

    Run:
    ./ExtendibleHashing
*/

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>

class Bucket {
public:
    int localDepth;
    std::vector<int> keys;

    explicit Bucket(int depth)
        : localDepth(depth) {}

    static constexpr int BUCKET_SIZE = 4;

    bool isFull() const {
        return keys.size() >= BUCKET_SIZE;
    }
};

class ExtendibleHash {
private:
    int globalDepth;
    std::vector<std::shared_ptr<Bucket>> directory;

    int hashKey(int key) const {
        return key;
    }

    int getIndex(int key) const {
        int mask = (1 << globalDepth) - 1;
        return hashKey(key) & mask;
    }

    void doubleDirectory() {
        size_t oldSize = directory.size();

        directory.resize(oldSize * 2);

        for (size_t i = 0; i < oldSize; ++i) {
            directory[i + oldSize] = directory[i];
        }

        ++globalDepth;
    }

    void splitBucket(int bucketIndex) {

        auto oldBucket = directory[bucketIndex];

        if (oldBucket->localDepth == globalDepth) {
            doubleDirectory();
        }

        auto newBucket =
            std::make_shared<Bucket>(
                oldBucket->localDepth + 1
            );

        oldBucket->localDepth++;

        int splitBit =
            1 << (oldBucket->localDepth - 1);

        for (size_t i = 0;
             i < directory.size();
             ++i) {

            if (directory[i] == oldBucket) {

                if (static_cast<int>(i) &
                    splitBit) {

                    directory[i] = newBucket;
                }
            }
        }

        std::vector<int> oldKeys =
            oldBucket->keys;

        oldBucket->keys.clear();

        for (int key : oldKeys) {

            int index =
                getIndex(key);

            directory[index]
                ->keys
                .push_back(key);
        }
    }

public:
    ExtendibleHash()
        : globalDepth(1) {

        directory.resize(2);

        directory[0] =
            std::make_shared<Bucket>(1);

        directory[1] =
            std::make_shared<Bucket>(1);
    }

    void insert(int key) {

        while (true) {

            int index =
                getIndex(key);

            auto bucket =
                directory[index];

            if (!bucket->isFull()) {

                bucket->keys
                    .push_back(key);

                return;
            }

            splitBucket(index);
        }
    }

    bool search(int key) const {

        int index =
            getIndex(key);

        auto bucket =
            directory[index];

        for (int value :
             bucket->keys) {

            if (value == key) {
                return true;
            }
        }

        return false;
    }

    bool remove(int key) {

        int index =
            getIndex(key);

        auto bucket =
            directory[index];

        for (auto it =
                 bucket->keys.begin();
             it != bucket->keys.end();
             ++it) {

            if (*it == key) {

                bucket->keys.erase(it);

                return true;
            }
        }

        return false;
    }

    void display() const {

        std::cout
            << "\nGlobal Depth: "
            << globalDepth
            << "\n";

        std::cout
            << "Directory Size: "
            << directory.size()
            << "\n\n";

        for (size_t i = 0;
             i < directory.size();
             ++i) {

            auto bucket =
                directory[i];

            std::cout
                << "Dir[" << i
                << "] -> LD="
                << bucket->localDepth
                << " : ";

            for (int key :
                 bucket->keys) {

                std::cout
                    << key << " ";
            }

            std::cout << "\n";
        }
    }
};

int main() {

    ExtendibleHash hash;

    std::vector<int> values = {
        5, 12, 25, 33,
        41, 18, 29, 37,
        49, 52, 61, 73
    };

    for (int value :
         values) {

        hash.insert(value);
    }

    hash.display();

    std::cout
        << "\nSearch 29: "
        << (hash.search(29)
                ? "Found"
                : "Not Found")
        << "\n";

    std::cout
        << "Search 100: "
        << (hash.search(100)
                ? "Found"
                : "Not Found")
        << "\n";

    hash.remove(29);

    std::cout
        << "\nAfter deleting 29:\n";

    hash.display();

    return 0;
}
