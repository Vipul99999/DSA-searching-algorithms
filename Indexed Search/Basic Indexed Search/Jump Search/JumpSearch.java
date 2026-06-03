public class JumpSearch {

    public static int jumpSearch(int[] arr, int target) {

        int n = arr.length;

        int step = (int)Math.sqrt(n);

        int prev = 0;

        while (prev < n &&
                arr[Math.min(step, n) - 1] < target) {

            prev = step;

            step += (int)Math.sqrt(n);

            if (prev >= n)
                return -1;
        }

        while (prev < n && arr[prev] < target)
            prev++;

        if (prev < n && arr[prev] == target)
            return prev;

        return -1;
    }

    public static void main(String[] args) {

        int[] arr = {
            2,5,8,12,16,
            23,38,56,72,91
        };

        int target = 23;

        int result =
                jumpSearch(arr, target);

        if(result!=-1)
            System.out.println(
                "Element found at index "
                + result
            );
        else
            System.out.println(
                "Element not found"
            );
    }
}
