public class UnboundedBinarySearch {

    static int binarySearch(
            int[] arr,
            int left,
            int right,
            int target) {

        while (left <= right) {

            int mid =
                    left +
                    (right - left) / 2;

            if (arr[mid] == target)
                return mid;

            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    static int search(
            int[] arr,
            int target) {

        if (arr.length == 0)
            return -1;

        if (arr[0] == target)
            return 0;

        int index = 1;

        while (
                index < arr.length &&
                arr[index] < target
        )
            index *= 2;

        int left = index / 2;
        int right =
                Math.min(
                        index,
                        arr.length - 1
                );

        return binarySearch(
                arr,
                left,
                right,
                target
        );
    }

    public static void main(String[] args) {

        int[] arr =
        {
                5,10,15,20,
                25,30,35,
                40,45,50
        };

        int target = 35;

        int result =
                search(
                        arr,
                        target
                );

        if (result != -1)
            System.out.println(
                    "Found at index "
                    + result
            );
        else
            System.out.println(
                    "Not Found"
            );
    }
}
