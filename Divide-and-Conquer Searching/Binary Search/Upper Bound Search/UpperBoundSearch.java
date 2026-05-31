public class UpperBoundSearch {

    public static int upperBoundSearch(
            int[] arr,
            int target) {

        int left = 0;
        int right = arr.length - 1;
        int answer = arr.length;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (arr[mid] > target) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    public static void main(String[] args) {

        int[] arr = {1, 3, 3, 3, 5, 7, 9};
        int target = 3;

        int index = upperBoundSearch(
                arr,
                target
        );

        if (index < arr.length) {
            System.out.println(
                    "Upper Bound of " +
                    target +
                    " is at index " +
                    index
            );
        } else {
            System.out.println(
                    "Upper Bound position is at end of array (" +
                    index +
                    ")"
            );
        }
    }
}
