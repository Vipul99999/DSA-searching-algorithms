#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* next;

    Node(int k)
        : key(k),
          next(nullptr) {}
};

class HashTable {
private:
    static constexpr int TABLE_SIZE = 10;

    std::vector<Node*> buckets;

    int hashFunction(int key) const {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
        : buckets(TABLE_SIZE, nullptr) {}

    void insert(int key) {

        int index =
            hashFunction(key);

        Node* node =
            new Node(key);

        node->next =
            buckets[index];

        buckets[index] = node;
    }

    bool search(int key) const {

        int index =
            hashFunction(key);

        Node* current =
            buckets[index];

        while (current) {

            if (current->key == key)
                return true;

            current =
                current->next;
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
                << "] -> ";

            Node* current =
                buckets[i];

            while (current) {

                std::cout
                    << current->key
                    << " -> ";

                current =
                    current->next;
            }

            std::cout
                << "NULL\n";
        }
    }

    ~HashTable() {

        for (Node* head :
             buckets) {

            while (head) {

                Node* temp =
                    head;

                head =
                    head->next;

                delete temp;
            }
        }
    }
};

int main() {

    HashTable ht;

    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(42);

    ht.display();

    std::cout
        << "\nSearch 35: "
        << (ht.search(35)
                ? "Found"
                : "Not Found")
        << '\n';
}
