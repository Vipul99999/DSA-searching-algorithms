#include <iostream>
#include <vector>

class HopscotchHashTable {

private:

    static constexpr int
        TABLE_SIZE = 16;

    static constexpr int
        HOP_RANGE = 4;

    struct Bucket {

        int key = -1;

        bool occupied =
            false;

        unsigned int hopInfo =
            0;
    };

    std::vector<Bucket> table;

    int hashFunction(
        int key
    ) const {

        return key % TABLE_SIZE;
    }

public:

    HopscotchHashTable()
        : table(TABLE_SIZE) {}

    bool insert(
        int key
    ) {

        int home =
            hashFunction(key);

        int freePos = -1;

        for (
            int i = home;
            i < TABLE_SIZE;
            i++
        ) {

            if (
                !table[i]
                .occupied
            ) {

                freePos = i;
                break;
            }
        }

        if (freePos == -1)
            return false;

        if (
            freePos - home >=
            HOP_RANGE
        )
            return false;

        table[
            freePos
        ].key = key;

        table[
            freePos
        ].occupied = true;

        table[
            home
        ].hopInfo |=
            (
                1U <<
                (
                    freePos
                    - home
                )
            );

        return true;
    }

    bool search(
        int key
    ) const {

        int home =
            hashFunction(key);

        unsigned int hop =
            table[home]
            .hopInfo;

        for (
            int i = 0;
            i < HOP_RANGE;
            i++
        ) {

            if (
                hop &
                (1U << i)
            ) {

                int pos =
                    home + i;

                if (
                    pos <
                    TABLE_SIZE &&
                    table[pos]
                    .occupied &&
                    table[pos]
                    .key == key
                ) {

                    return true;
                }
            }
        }

        return false;
    }

    void display()
    const {

        std::cout
            << "\nHopscotch "
            << "Hash Table\n";

        for (
            int i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            std::cout
                << "[" << i
                << "] = ";

            if (
                table[i]
                .occupied
            ) {

                std::cout
                    << table[i]
                    .key;
            }
            else {

                std::cout
                    << "EMPTY";
            }

            std::cout
                << " (hop="
                << table[i]
                .hopInfo
                << ")\n";
        }
    }
};

int main() {

    HopscotchHashTable ht;

    ht.insert(5);
    ht.insert(21);
    ht.insert(37);
    ht.insert(53);

    ht.display();

    std::cout
        << "\nSearch 37: "
        << (
            ht.search(37)
            ? "Found"
            : "Not Found"
        )
        << '\n';
}
