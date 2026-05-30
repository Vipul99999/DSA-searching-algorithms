class FrequencyCountSearch {
    constructor(arr) {
        this.data = [...arr];
        this.frequency = new Array(arr.length).fill(0);
    }

    search(target) {
        for (let i = 0; i < this.data.length; i++) {

            if (this.data[i] === target) {

                this.frequency[i]++;

                while (
                    i > 0 &&
                    this.frequency[i] >
                        this.frequency[i - 1]
                ) {
                    [
                        this.frequency[i],
                        this.frequency[i - 1]
                    ] = [
                        this.frequency[i - 1],
                        this.frequency[i]
                    ];

                    [
                        this.data[i],
                        this.data[i - 1]
                    ] = [
                        this.data[i - 1],
                        this.data[i]
                    ];

                    i--;
                }

                return i;
            }
        }

        return -1;
    }

    printState() {
        console.log(
            "Elements  :",
            this.data.join(" ")
        );

        console.log(
            "Frequency :",
            this.frequency.join(" ")
        );
    }
}

function main() {

    const searcher =
        new FrequencyCountSearch(
            [10, 20, 30, 40, 50]
        );

    searcher.printState();

    searcher.search(40);
    searcher.search(40);
    searcher.search(20);
    searcher.search(40);

    console.log("\nAfter Searches:");
    searcher.printState();
}

main();
