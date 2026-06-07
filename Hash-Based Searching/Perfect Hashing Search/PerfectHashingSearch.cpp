#include <iostream>
#include <vector>

class PerfectHashTable {

private:

    static constexpr int EMPTY = -1;

    std::vector<int> table;

    int perfectHash(
        int key
    ) const {

        switch(key) {

            case 11: return 0;
            case 22: return 1;
            case 33: return 2;
            case 44: return 3;
            case 55: return 4;

            default:
                return -1;
        }
    }

public:

    PerfectHashTable()
        : table(10, EMPTY)
    {
        table[0] = 11;
        table[1] = 22;
        table[2] = 33;
        table[3] = 44;
        table[4] = 55;
    }

    bool search(
        int key
    ) const {

        int idx =
            perfectHash(key);

        if (idx == -1)
            return false;

        return table[idx] == key;
    }
};

int main() {

    PerfectHashTable ht;

    std::cout
        << "Search 33: "
        << (
            ht.search(33)
            ? "Found"
            : "Not Found"
        )
        << '\n';
}
