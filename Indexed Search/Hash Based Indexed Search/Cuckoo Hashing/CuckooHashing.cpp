#include <iostream>
#include <vector>

using namespace std;

class CuckooHash {

private:

    static const int SIZE = 11;
    static const int EMPTY = -1;
    static const int MAX_KICKS = 20;

    vector<int> table1;
    vector<int> table2;

    int hash1(int key) {
        return key % SIZE;
    }

    int hash2(int key) {
        return (key / SIZE) % SIZE;
    }

public:

    CuckooHash() {

        table1.assign(
            SIZE,
            EMPTY
        );

        table2.assign(
            SIZE,
            EMPTY
        );
    }

    bool search(int key) {

        return (
            table1[hash1(key)] == key ||
            table2[hash2(key)] == key
        );
    }

    bool insert(int key) {

        if (search(key))
            return true;

        int current = key;

        bool first = true;

        for (
            int i = 0;
            i < MAX_KICKS;
            i++
        ) {

            if (first) {

                int idx =
                    hash1(current);

                if (
                    table1[idx]
                    ==
                    EMPTY
                ) {

                    table1[idx] =
                        current;

                    return true;
                }

                swap(
                    current,
                    table1[idx]
                );

                first = false;

            } else {

                int idx =
                    hash2(current);

                if (
                    table2[idx]
                    ==
                    EMPTY
                ) {

                    table2[idx] =
                        current;

                    return true;
                }

                swap(
                    current,
                    table2[idx]
                );

                first = true;
            }
        }

        return false;
    }

    void remove(int key) {

        if (
            table1[hash1(key)]
            ==
            key
        )
            table1[
                hash1(key)
            ] = EMPTY;

        if (
            table2[hash2(key)]
            ==
            key
        )
            table2[
                hash2(key)
            ] = EMPTY;
    }
};

int main() {

    CuckooHash h;

    h.insert(20);
    h.insert(35);

    cout
        << h.search(35);

}
