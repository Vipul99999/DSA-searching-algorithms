public class BinarySearchOnAnswer {

    private static boolean canComplete(
            int speed,
            int[] piles,
            int hours) {

        long totalHours = 0;

        for (int pile : piles) {

            totalHours +=
                    (pile + speed - 1) / speed;

            if (totalHours > hours) {
                return false;
            }
        }

        return true;
    }

    public static int solve(
            int[] piles,
            int hours) {

        int left = 1;
        int right = piles[0];

        for (int pile : piles) {
            right = Math.max(right, pile);
        }

        int answer = right;

        while (left <= right) {

            int mid =
                    left + (right - left) / 2;

            if (canComplete(
                    mid,
                    piles,
                    hours)) {

                answer = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return answer;
    }

    public static void main(String[] args) {

        int[] piles =
        {
            3, 6, 7, 11
        };

        int hours = 8;

        System.out.println(
                "Minimum Speed: " +
                solve(piles, hours)
        );
    }
}
