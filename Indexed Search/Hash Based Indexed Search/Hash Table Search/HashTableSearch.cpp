#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {

private:

    static const int TABLE_SIZE = 10;

    vector<list<int>> table;

    int hash(int key) {

        // h(key)=key%TABLE_SIZE
        return key % TABLE_SIZE;
    }

public:

    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(int key) {

        int index = hash(key);

        table[index].push_back(key);
    }

    bool search(int key) {

        int index = hash(key);

        for (int value : table[index]) {

            if (value == key)
                return true;
        }

        return false;
    }

    void remove(int key) {

        int index = hash(key);

        table[index].remove(key);
    }

    void display() {

        for (
            int i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            cout << "[" << i << "] ";

            for (
                int value :
                table[i]
            ) {
                cout
                    << value
                    << " -> ";
            }

            cout << "NULL\n";
        }
    }
};

int main() {

    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(35);

    ht.display();

    cout
        << "\nSearch 20: "
        << ht.search(20);

    ht.remove(20);

    cout << "\n\nAfter Delete\n";

    ht.display();
}
