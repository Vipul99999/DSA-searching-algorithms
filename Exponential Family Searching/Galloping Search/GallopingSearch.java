public class GallopingSearch {

    static int binarySearch(
            int[] arr,
            int left,
            int right,
            int target
    ) {

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

    static int gallopingSearch(
            int[] arr,
            int target
    ) {

        if (arr.length == 0)
            return -1;

        if (arr[0] == target)
            return 0;

        int bound = 1;

        while (
            bound < arr.length &&
            arr[bound] < target
        ) {
            bound *= 2;
        }

        return binarySearch(
            arr,
            bound / 2,
            Math.min(
                bound,
                arr.length - 1
            ),
            target
        );
    }

    public static void main(
            String[] args
    ) {

        int[] arr = {
            5,10,15,20,
            25,30,35,
            40,45,50
        };

        int target = 35;

        int result =
            gallopingSearch(
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
