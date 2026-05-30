public class TransposeSearch {

    public static int transposeSearch(int[] arr, int target) {

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] == target) {

                if (i > 0) {

                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;

                    return i - 1;
                }

                return i;
            }
        }

        return -1;
    }

    public static void printArray(int[] arr) {

        for (int value : arr) {
            System.out.print(value + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50};
        int target = 40;

        System.out.println("Before Search:");
        printArray(arr);

        int index = transposeSearch(arr, target);

        if (index != -1) {
            System.out.println("Element found.");
        } else {
            System.out.println("Element not found.");
        }

        System.out.println("After Search:");
        printArray(arr);
    }
}
