public class IterativeBinarySearch {

    public static int iterativeBinarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        int[] arr = {5, 12, 18, 25, 31, 42, 56};
        int target = 31;

        int index = iterativeBinarySearch(arr, target);

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
