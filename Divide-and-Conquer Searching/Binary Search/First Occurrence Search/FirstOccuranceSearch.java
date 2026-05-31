public class FirstOccurrenceSearch {

    public static int firstOccurrenceSearch(
            int[] arr,
            int target) {

        int left = 0;
        int right = arr.length - 1;
        int answer = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                answer = mid;
                right = mid - 1;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }

    public static void main(String[] args) {

        int[] arr = {
                1, 3, 3, 3, 5, 7, 9
        };

        int target = 3;

        int index = firstOccurrenceSearch(
                arr,
                target
        );

        if (index != -1) {
            System.out.println(
                    "First occurrence of " +
                    target +
                    " found at index " +
                    index
            );
        } else {
            System.out.println(
                    target +
                    " not found in array"
            );
        }
    }
}
