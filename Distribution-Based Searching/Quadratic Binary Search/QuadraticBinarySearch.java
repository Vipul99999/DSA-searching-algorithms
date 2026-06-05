public class QuadraticBinarySearch {

    static int search(
        int[] arr,
        int target
    ) {

        int low = 0;

        int high =
            arr.length - 1;

        while (
            low <= high
        ) {

            int range =
                high - low;

            int pos =
                low +
                (
                    range *
                    range
                )
                /
                (
                    2 *
                    (
                        range + 1
                    )
                );

            if (
                pos > high
            )
                pos =
                    low +
                    range / 2;

            if (
                arr[pos]
                ==
                target
            )
                return pos;

            if (
                arr[pos]
                <
                target
            )
                low =
                    pos + 1;
            else
                high =
                    pos - 1;
        }

        return -1;
    }

    public static void main(
        String[] args
    ) {

        int[] arr =
        {
            10,
            20,
            30,
            40,
            50,
            60,
            70,
            80,
            90
        };

        System.out.println(
            search(
                arr,
                70
            )
        );
    }
}
