class FrequencyCountSearch:

    def __init__(self, arr):
        self.data = arr[:]
        self.frequency = [0] * len(arr)

    def search(self, target):

        for i in range(len(self.data)):

            if self.data[i] == target:

                self.frequency[i] += 1

                while (
                    i > 0
                    and self.frequency[i] > self.frequency[i - 1]
                ):
                    self.frequency[i], self.frequency[i - 1] = (
                        self.frequency[i - 1],
                        self.frequency[i],
                    )

                    self.data[i], self.data[i - 1] = (
                        self.data[i - 1],
                        self.data[i],
                    )

                    i -= 1

                return i

        return -1

    def print_state(self):
        print("Elements  :", *self.data)
        print("Frequency :", *self.frequency)


def main():
    searcher = FrequencyCountSearch(
        [10, 20, 30, 40, 50]
    )

    searcher.print_state()

    searcher.search(40)
    searcher.search(40)
    searcher.search(20)
    searcher.search(40)

    print("\nAfter Searches:")
    searcher.print_state()


if __name__ == "__main__":
    main()
