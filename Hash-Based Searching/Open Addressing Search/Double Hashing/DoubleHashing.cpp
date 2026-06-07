#include <iostream>
#include <vector>

class DoubleHashTable {
private:

    static constexpr int TABLE_SIZE = 13;
    static constexpr int EMPTY = -1;

    std::vector<int> table;

    int hash1(int key) const {
        return key % TABLE_SIZE;
    }

    int hash2(int key) const {
        return 7 - (key % 7);
    }

public:

    DoubleHashTable()
        : table(TABLE_SIZE, EMPTY) {}

    bool insert(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            int pos =
                (h1 + i * h2)
                % TABLE_SIZE;

            if (table[pos] == EMPTY) {

                table[pos] = key;

                return true;
            }
        }

        return false;
    }

    bool search(int key) const {

        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            int pos =
                (h1 + i * h2)
                % TABLE_SIZE;

            if (table[pos] == EMPTY)
                return false;

            if (table[pos] == key)
                return true;
        }

        return false;
    }

    void display() const {

        std::cout
            << "\nHash Table\n";

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            std::cout
                << "[" << i
                << "] = ";

            if (table[i] == EMPTY)
                std::cout << "EMPTY";
            else
                std::cout << table[i];

            std::cout << '\n';
        }
    }
};

int main() {

    DoubleHashTable ht;

    ht.insert(25);
    ht.insert(38);
    ht.insert(51);
    ht.insert(64);

    ht.display();

    std::cout
        << "\nSearch 51: "
        << (ht.search(51)
            ? "Found"
            : "Not Found")
        << '\n';
}
