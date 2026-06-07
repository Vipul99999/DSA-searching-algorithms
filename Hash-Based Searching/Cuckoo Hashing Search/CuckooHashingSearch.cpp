#include <iostream>
#include <vector>

using namespace std;

class CuckooHash {
    static const int TABLE_SIZE = 11;
    static const int EMPTY = -1;
    static const int MAX_KICKS = 20;

    vector<int> table1;
    vector<int> table2;

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return (key / TABLE_SIZE) % TABLE_SIZE;
    }

public:
    CuckooHash()
        : table1(TABLE_SIZE, EMPTY),
          table2(TABLE_SIZE, EMPTY) {}

    bool search(int key) {
        return table1[hash1(key)] == key ||
               table2[hash2(key)] == key;
    }

    bool insert(int key) {
        int current = key;
        int table = 1;

        for (int i = 0; i < MAX_KICKS; i++) {
            if (table == 1) {
                int pos = hash1(current);

                if (table1[pos] == EMPTY) {
                    table1[pos] = current;
                    return true;
                }

                swap(current, table1[pos]);
                table = 2;
            } else {
                int pos = hash2(current);

                if (table2[pos] == EMPTY) {
                    table2[pos] = current;
                    return true;
                }

                swap(current, table2[pos]);
                table = 1;
            }
        }

        return false;
    }
};

int main() {
    CuckooHash hash;

    hash.insert(20);
    hash.insert(50);
    hash.insert(53);
    hash.insert(75);

    cout << (hash.search(53)
                ? "Found"
                : "Not Found")
         << endl;
}
