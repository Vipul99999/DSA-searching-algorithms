#include <iostream>
#include <vector>

class LinearProbingHashTable {
private:
    static constexpr int TABLE_SIZE = 11;
    static constexpr int EMPTY = -1;

    std::vector<int> table;

    int hashFunction(int key) const {
        return key % TABLE_SIZE;
    }

public:
    LinearProbingHashTable()
        : table(TABLE_SIZE, EMPTY) {}

    bool insert(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int pos = (index + i) % TABLE_SIZE;

            if (table[pos] == EMPTY) {
                table[pos] = key;
                return true;
            }
        }

        return false;
    }

    bool search(int key) const {
        int index = hashFunction(key);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int pos = (index + i) % TABLE_SIZE;

            if (table[pos] == EMPTY)
                return false;

            if (table[pos] == key)
                return true;
        }

        return false;
    }

    void display() const {
        std::cout << "\nHash Table\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            std::cout << "[" << i << "] = ";

            if (table[i] == EMPTY)
                std::cout << "EMPTY";
            else
                std::cout << table[i];

            std::cout << '\n';
        }
    }
};

int main() {
    LinearProbingHashTable ht;

    ht.insert(22);
    ht.insert(33);
    ht.insert(44);
    ht.insert(55);

    ht.display();

    std::cout
        << "\nSearch 44: "
        << (ht.search(44)
                ? "Found"
                : "Not Found")
        << '\n';

    return 0;
}
