public class SentinelLinearSearch {

    public static int sentinelLinearSearch(int[] arr, int target) {
        int n = arr.length;

        if (n == 0) {
            return -1;
        }

        int last = arr[n - 1];

        arr[n - 1] = target;

        int i = 0;
        while (arr[i] != target) {
            i++;
        }

        arr[n - 1] = last;

        if (i < n - 1 || last == target) {
            return i;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10, 25, 7, 14, 30};
        int target = 14;

        int index = sentinelLinearSearch(arr, target);

        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found");
        }
    }
}
