#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int frequency[MAX_SIZE];
    int size;
} FrequencyCountSearch;

void initialize(
    FrequencyCountSearch* searcher,
    int arr[],
    int size
) {
    searcher->size = size;

    for (int i = 0; i < size; i++) {
        searcher->data[i] = arr[i];
        searcher->frequency[i] = 0;
    }
}

int search(
    FrequencyCountSearch* searcher,
    int target
) {

    for (int i = 0; i < searcher->size; i++) {

        if (searcher->data[i] == target) {

            searcher->frequency[i]++;

            while (
                i > 0 &&
                searcher->frequency[i] >
                searcher->frequency[i - 1]
            ) {

                int tempFreq =
                    searcher->frequency[i];

                searcher->frequency[i] =
                    searcher->frequency[i - 1];

                searcher->frequency[i - 1] =
                    tempFreq;

                int tempData =
                    searcher->data[i];

                searcher->data[i] =
                    searcher->data[i - 1];

                searcher->data[i - 1] =
                    tempData;

                i--;
            }

            return i;
        }
    }

    return -1;
}

void printState(
    FrequencyCountSearch* searcher
) {

    printf("Elements  : ");

    for (int i = 0; i < searcher->size; i++) {
        printf("%d ", searcher->data[i]);
    }

    printf("\nFrequency : ");

    for (int i = 0; i < searcher->size; i++) {
        printf("%d ", searcher->frequency[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {10, 20, 30, 40, 50};

    FrequencyCountSearch searcher;

    initialize(
        &searcher,
        arr,
        sizeof(arr) / sizeof(arr[0])
    );

    printState(&searcher);

    search(&searcher, 40);
    search(&searcher, 40);
    search(&searcher, 20);
    search(&searcher, 40);

    printf("\nAfter Searches:\n");

    printState(&searcher);

    return 0;
}
