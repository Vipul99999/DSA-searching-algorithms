public class FractionalCascadingSearch {

    static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    public static void main(String[] args) {

        int[][] catalogs = {
            {1,4,7,10,13},
            {2,5,8,11,14},
            {3,6,9,12,15}
        };

        int target = 11;

        for (int i = 0; i < catalogs.length; i++) {
            System.out.println(
                "Catalog " + (i + 1) +
                ": " +
                binarySearch(catalogs[i], target)
            );
        }
    }
}
