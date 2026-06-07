#include <iostream>
#include <vector>

class RobinHoodHash {

private:

    static constexpr int TABLE_SIZE = 11;
    static constexpr int EMPTY = -1;

    std::vector<int> table;

    int hashFunction(
        int key
    ) const {

        return key % TABLE_SIZE;
    }

    int probeDistance(
        int key,
        int pos
    ) const {

        int home =
            hashFunction(key);

        return (
            pos - home +
            TABLE_SIZE
        ) % TABLE_SIZE;
    }

public:

    RobinHoodHash()
        : table(
            TABLE_SIZE,
            EMPTY
        ) {}

    bool insert(int key) {

        int current = key;

        int pos =
            hashFunction(
                current
            );

        while (true) {

            if (
                table[pos]
                == EMPTY
            ) {

                table[pos] =
                    current;

                return true;
            }

            int resident =
                table[pos];

            int currentDist =
                probeDistance(
                    current,
                    pos
                );

            int residentDist =
                probeDistance(
                    resident,
                    pos
                );

            if (
                currentDist >
                residentDist
            ) {

                std::swap(
                    current,
                    table[pos]
                );
            }

            pos =
                (pos + 1)
                % TABLE_SIZE;
        }
    }

    bool search(
        int key
    ) const {

        int pos =
            hashFunction(
                key
            );

        int dist = 0;

        while (
            table[pos]
            != EMPTY
        ) {

            if (
                table[pos]
                == key
            ) {
                return true;
            }

            int residentDist =
                probeDistance(
                    table[pos],
                    pos
                );

            if (
                residentDist <
                dist
            ) {
                return false;
            }

            pos =
                (pos + 1)
                % TABLE_SIZE;

            dist++;
        }

        return false;
    }

    void display()
    const {

        std::cout
            << "\nHash Table\n";

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
                == EMPTY
            )
                std::cout
                    << "EMPTY";
            else
                std::cout
                    << table[i];

            std::cout
                << '\n';
        }
    }
};

int main() {

    RobinHoodHash ht;

    ht.insert(22);
    ht.insert(33);
    ht.insert(44);
    ht.insert(55);
    ht.insert(66);

    ht.display();

    std::cout
        << "\nSearch 44: "
        << (
            ht.search(44)
            ? "Found"
            : "Not Found"
        )
        << '\n';
}
