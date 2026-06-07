#include <iostream>
#include <vector>

class HashTable {
private:
    static constexpr int TABLE_SIZE = 101;
    static constexpr int EMPTY = -1;

    std::vector<int> table;

    int hashFunction(int key) const {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
        : table(TABLE_SIZE, EMPTY) {}

    bool insert(int key) {
        int index = hashFunction(key);

        if (table[index] != EMPTY)
            return false;

        table[index] = key;
        return true;
    }

    bool lookup(int key) const {
        return table[hashFunction(key)] == key;
    }
};

int main() {
    HashTable ht;

    ht.insert(15);
    ht.insert(42);
    ht.insert(99);

    std::cout
        << (ht.lookup(42)
                ? "Found"
                : "Not Found")
        << '\n';

    return 0;
}
