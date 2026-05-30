import java.util.Arrays;

public class MoveToFrontSearch {

    public static int moveToFrontSearch(int[] arr, int target) {

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] == target) {

                int foundElement = arr[i];

                while (i > 0) {
                    arr[i] = arr[i - 1];
                    i--;
                }

                arr[0] = foundElement;

                return 0;
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

        int result = moveToFrontSearch(arr, target);

        if (result != -1) {
            System.out.println("Element found and moved to front.");
        } else {
            System.out.println("Element not found.");
        }

        System.out.println("After Search:");
        printArray(arr);
    }
}
