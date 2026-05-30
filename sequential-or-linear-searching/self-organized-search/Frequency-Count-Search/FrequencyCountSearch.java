public class FrequencyCountSearch {

    private int[] data;
    private int[] frequency;

    public FrequencyCountSearch(int[] arr) {

        data = arr.clone();
        frequency = new int[arr.length];
    }

    public int search(int target) {

        for (int i = 0; i < data.length; i++) {

            if (data[i] == target) {

                frequency[i]++;

                while (
                    i > 0 &&
                    frequency[i] >
                    frequency[i - 1]
                ) {

                    int tempFreq =
                        frequency[i];

                    frequency[i] =
                        frequency[i - 1];

                    frequency[i - 1] =
                        tempFreq;

                    int tempData =
                        data[i];

                    data[i] =
                        data[i - 1];

                    data[i - 1] =
                        tempData;

                    i--;
                }

                return i;
            }
        }

        return -1;
    }

    public void printState() {

        System.out.print("Elements  : ");

        for (int value : data) {
            System.out.print(value + " ");
        }

        System.out.println();

        System.out.print("Frequency : ");

        for (int count : frequency) {
            System.out.print(count + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        FrequencyCountSearch searcher =
            new FrequencyCountSearch(
                new int[]{
                    10, 20, 30, 40, 50
                }
            );

        searcher.printState();

        searcher.search(40);
        searcher.search(40);
        searcher.search(20);
        searcher.search(40);

        System.out.println(
            "\nAfter Searches:"
        );

        searcher.printState();
    }
}
