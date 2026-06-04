#include <iostream>
#include <unordered_set>

using namespace std;

class PerfectHash {

private:

    unordered_set<int> data;

public:

    void build(
        int keys[],
        int n
    ) {

        for (
            int i = 0;
            i < n;
            i++
        )
            data.insert(
                keys[i]
            );
    }

    bool search(
        int key
    ) {

        return
            data.count(
                key
            );
    }
};

int main() {

    int keys[] =
    {
        10,
        20,
        42
    };

    PerfectHash ph;

    ph.build(
        keys,
        3
    );

    cout
    <<
    ph.search(
        42
    );
}
