public class InterpolationBinaryHybrid {

    static int search(
        int[] arr,
        int target
    ) {

        int low = 0;
        int high =
            arr.length - 1;

        while (
            low <= high &&
            target >= arr[low] &&
            target <= arr[high]
        ) {

            if (
                arr[low]
                ==
                arr[high]
            )
                return
                    arr[low]
                    ==
                    target
                    ? low
                    : -1;

            int pos =
                low +
                (int)(
                    (
                        (
                            double
                        )
                        (
                            target
                            -
                            arr[low]
                        )
                        *
                        (
                            high
                            -
                            low
                        )
                    )
                    /
                    (
                        arr[high]
                        -
                        arr[low]
                    )
                );

            if (
                pos < low ||
                pos > high
            )
                pos =
                    low +
                    (
                        high -
                        low
                    ) / 2;

            if (
                arr[pos]
                ==
                target
            )
                return pos;

            if (
                high -
                low < 6
            ) {

                int mid =
                    low +
                    (
                        high -
                        low
                    ) / 2;

                if (
                    arr[mid]
                    ==
                    target
                )
                    return mid;

                if (
                    arr[mid]
                    <
                    target
                )
                    low =
                        mid + 1;
                else
                    high =
                        mid - 1;

                continue;
            }

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
            1000,
            5000
        };

        System.out.println(
            search(
                arr,
                1000
            )
        );
    }
}
