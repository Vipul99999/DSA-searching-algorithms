#include <iostream>
#include <vector>

using namespace std;

/*
-------------------------------------
Configuration
-------------------------------------
*/
const int BUCKET_SIZE = 3;


/*
-------------------------------------
Bucket Structure
-------------------------------------
localDepth:
Number of bits used by this bucket
-------------------------------------
*/
class Bucket {
public:

    int localDepth;

    vector<int> keys;

    Bucket(int depth)
        : localDepth(depth) {}

    bool isFull() const {
        return keys.size() >= BUCKET_SIZE;
    }

    bool contains(int key) const {

        for (int value : keys) {
            if (value == key)
                return true;
        }

        return false;
    }
};


/*
-------------------------------------
Dynamic Hash Table
(Extendible Hashing)
-------------------------------------

Directory Index Formula:

index =
hash(key)
&
((1 << globalDepth) - 1)

-------------------------------------
*/
class DynamicHashing {

private:

    int globalDepth;

    vector<Bucket*> directory;

private:

    int getIndex(int key) {

        return key &
               (
                   (1 << globalDepth)
                   - 1
               );
    }


    /*
    Double directory size
    */
    void expandDirectory() {

        int oldSize =
            directory.size();

        directory.resize(
            oldSize * 2
        );

        for (
            int i = 0;
            i < oldSize;
            i++
        ) {
            directory[
                i + oldSize
            ] =
            directory[i];
        }

        globalDepth++;
    }


    /*
    Split overflowing bucket
    */
    void splitBucket(
        int index
    ) {

        Bucket* old =
            directory[index];

        if (
            old->localDepth
            ==
            globalDepth
        ) {

            expandDirectory();
        }

        Bucket* fresh =
            new Bucket(
                old->localDepth
                + 1
            );

        old->localDepth++;

        int bitMask =
            1
            <<
            (
                old->localDepth
                - 1
            );

        for (
            int i = 0;
            i < directory.size();
            i++
        ) {

            if (
                directory[i]
                ==
                old
                &&
                (
                    i & bitMask
                )
            ) {

                directory[i] =
                    fresh;
            }
        }

        vector<int> oldValues =
            old->keys;

        old->keys.clear();

        for (
            int key :
            oldValues
        ) {

            int newIndex =
                getIndex(key);

            directory[
                newIndex
            ]
            ->
            keys
            .push_back(
                key
            );
        }
    }

public:

    DynamicHashing() {

        globalDepth = 1;

        directory.resize(2);

        directory[0] =
            new Bucket(1);

        directory[1] =
            new Bucket(1);
    }


    /*
    Insert key
    */
    void insert(
        int key
    ) {

        while (true) {

            int index =
                getIndex(
                    key
                );

            Bucket* bucket =
                directory[
                    index
                ];

            if (
                bucket
                ->
                contains(
                    key
                )
            ) {
                return;
            }

            if (
                !bucket
                 ->
                 isFull()
            ) {

                bucket
                ->
                keys
                .push_back(
                    key
                );

                return;
            }

            splitBucket(
                index
            );
        }
    }


    /*
    Search
    */
    bool search(
        int key
    ) {

        int index =
            getIndex(
                key
            );

        return
            directory[
                index
            ]
            ->
            contains(
                key
            );
    }


    /*
    Delete
    */
    void remove(
        int key
    ) {

        int index =
            getIndex(
                key
            );

        auto& keys =
            directory[
                index
            ]
            ->
            keys;

        for (
            auto it =
            keys.begin();

            it
            !=
            keys.end();

            it++
        ) {

            if (
                *it
                ==
                key
            ) {

                keys.erase(
                    it
                );

                return;
            }
        }
    }


    /*
    Display
    */
    void display() {

        cout
        <<
        "\nGlobal Depth: "
        <<
        globalDepth
        <<
        "\n\n";

        for (
            int i = 0;
            i < directory.size();
            i++
        ) {

            cout
            <<
            "Dir["
            <<
            i
            <<
            "] -> ";

            for (
                int value :
                directory[i]
                ->
                keys
            ) {

                cout
                <<
                value
                <<
                " ";
            }

            cout
            <<
            "\n";
        }
    }
};


/*
-------------------------------------
Driver
-------------------------------------
*/
int main() {

    DynamicHashing hash;

    hash.insert(10);

    hash.insert(22);

    hash.insert(14);

    hash.insert(30);

    hash.insert(42);

    hash.insert(54);

    hash.display();

    cout
    <<
    "\nSearch 42: "
    <<
    (
        hash.search(
            42
        )
        ?
        "Found"
        :
        "Not Found"
    );

    hash.remove(
        42
    );

    cout
    <<
    "\nAfter Delete\n";

    hash.display();

    return 0;
}
