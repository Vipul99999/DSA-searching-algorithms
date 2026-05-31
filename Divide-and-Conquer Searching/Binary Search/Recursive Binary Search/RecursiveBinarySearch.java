public class RecursiveBinarySearch {

    public static int recursiveBinarySearch(
            int[] arr,
            int left,
            int right,
            int target) {

        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            return recursiveBinarySearch(
                    arr,
                    mid + 1,
                    right,
                    target
            );
        }

        return recursiveBinarySearch(
                arr,
                left,
                mid - 1,
                target
        );
    }

    public static void main(String[] args) {

        int[] arr = {
                5, 12, 18, 25, 31, 42, 56
        };

        int target = 42;

        int index = recursiveBinarySearch(
                arr,
                0,
                arr.length - 1,
                target
        );

        if (index != -1) {
            System.out.println(
                    "Element " + target +
                    " found at index " + index
            );
        } else {
            System.out.println(
                    "Element " + target +
                    " not found"
            );
        }
    }
}
