#include <iostream>
#include <vector>
#include <utility>

class FrequencyCountSearch {
private:
    std::vector<int> data;
    std::vector<int> frequency;

public:
    explicit FrequencyCountSearch(const std::vector<int>& arr)
        : data(arr), frequency(arr.size(), 0) {}

    int search(int target) {
        int n = static_cast<int>(data.size());

        for (int i = 0; i < n; ++i) {

            if (data[i] == target) {

                frequency[i]++;

                while (i > 0 &&
                       frequency[i] > frequency[i - 1]) {

                    std::swap(frequency[i], frequency[i - 1]);
                    std::swap(data[i], data[i - 1]);

                    --i;
                }

                return i;
            }
        }

        return -1;
    }

    void print() const {
        std::cout << "Elements   : ";
        for (int value : data) {
            std::cout << value << " ";
        }

        std::cout << "\nFrequency : ";
        for (int count : frequency) {
            std::cout << count << " ";
        }

        std::cout << "\n";
    }
};

int main() {

    FrequencyCountSearch searcher({10, 20, 30, 40, 50});

    searcher.print();

    searcher.search(40);
    searcher.search(40);
    searcher.search(20);
    searcher.search(40);

    std::cout << "\nAfter Searches:\n";
    searcher.print();

    return 0;
}
