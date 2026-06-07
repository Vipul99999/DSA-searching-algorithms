/*
    LinearHashing.cpp
    Modern C++20

    Features:
    - Dynamic Bucket Growth
    - Split Pointer (next)
    - Level-Based Hashing
    - Bucket Splitting
    - Overflow Buckets
    - Insert
    - Search
    - Display

    Compile:
    g++ -std=c++20 LinearHashing.cpp -o LinearHashing

    Run:
    ./LinearHashing
*/

#include <iostream>
#include <vector>
#include <memory>

class Bucket {
public:
    static constexpr int BUCKET_SIZE = 4;

    std::vector<int> keys;
    std::unique_ptr<Bucket> overflow;

    bool isFull() const {
        return keys.size() >= BUCKET_SIZE;
    }
};

class LinearHashTable {
private:
    static constexpr int INITIAL_BUCKETS = 2;

    std::vector<std::unique_ptr<Bucket>> buckets;

    int level;
    int nextSplit;

    int hashLevel(int key) const {
        return key %
               (INITIAL_BUCKETS << level);
    }

    int hashNextLevel(int key) const {
        return key %
               (INITIAL_BUCKETS
                << (level + 1));
    }

    int bucketIndex(int key) const {

        int idx =
            hashLevel(key);

        if (idx < nextSplit) {
            idx =
                hashNextLevel(key);
        }

        return idx;
    }

    void insertIntoBucket(
        Bucket* bucket,
        int key
    ) {

        Bucket* current =
            bucket;

        while (true) {

            if (
                current->keys.size() <
                Bucket::BUCKET_SIZE
            ) {

                current->keys.push_back(
                    key
                );

                return;
            }

            if (!current->overflow) {

                current->overflow =
                    std::make_unique
                    <Bucket>();
            }

            current =
                current->overflow.get();
        }
    }

    void splitBucket() {

        int splitIndex =
            nextSplit;

        buckets.push_back(
            std::make_unique
            <Bucket>()
        );

        std::vector<int> values;

        Bucket* current =
            buckets[
                splitIndex
            ].get();

        while (current) {

            for (int value :
                 current->keys) {

                values.push_back(
                    value
                );
            }

            current =
                current->overflow.get();
        }

        buckets[splitIndex] =
            std::make_unique
            <Bucket>();

        for (int value :
             values) {

            int idx =
                hashNextLevel(
                    value
                );

            insertIntoBucket(
                buckets[idx].get(),
                value
            );
        }

        nextSplit++;

        int roundSize =
            INITIAL_BUCKETS
            << level;

        if (
            nextSplit ==
            roundSize
        ) {

            nextSplit = 0;
            level++;
        }
    }

public:
    LinearHashTable()
        : level(0),
          nextSplit(0) {

        for (
            int i = 0;
            i < INITIAL_BUCKETS;
            i++
        ) {

            buckets.push_back(
                std::make_unique
                <Bucket>()
            );
        }
    }

    void insert(int key) {

        int idx =
            bucketIndex(key);

        insertIntoBucket(
            buckets[idx].get(),
            key
        );

        splitBucket();
    }

    bool search(int key) const {

        int idx =
            bucketIndex(key);

        Bucket* current =
            buckets[idx].get();

        while (current) {

            for (
                int value :
                current->keys
            ) {

                if (value == key)
                    return true;
            }

            current =
                current
                ->overflow
                .get();
        }

        return false;
    }

    void display() const {

        std::cout
            << "\nLevel: "
            << level
            << "\n";

        std::cout
            << "Next Split: "
            << nextSplit
            << "\n";

        std::cout
            << "Bucket Count: "
            << buckets.size()
            << "\n\n";

        for (
            size_t i = 0;
            i < buckets.size();
            i++
        ) {

            std::cout
                << "Bucket["
                << i
                << "] : ";

            Bucket* current =
                buckets[i].get();

            while (current) {

                for (
                    int value :
                    current->keys
                ) {

                    std::cout
                        << value
                        << " ";
                }

                if (
                    current
                    ->overflow
                ) {

                    std::cout
                        << "-> ";
                }

                current =
                    current
                    ->overflow
                    .get();
            }

            std::cout
                << "\n";
        }
    }
};

int main() {

    LinearHashTable hash;

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
        << (
            hash.search(29)
            ? "Found"
            : "Not Found"
        )
        << "\n";

    std::cout
        << "Search 100: "
        << (
            hash.search(100)
            ? "Found"
            : "Not Found"
        )
        << "\n";

    return 0;
}
