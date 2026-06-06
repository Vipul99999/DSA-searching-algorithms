public class GoldenRatioSearch {

    static double objective(
            double x
    ) {

        return
        (x - 3) *
        (x - 3)
        + 5;
    }

    static double search(
            double left,
            double right,
            double tolerance
    ) {

        double phi =
                (1 +
                Math.sqrt(5))
                / 2;

        double x1 =
                right -
                (
                right-left
                ) / phi;

        double x2 =
                left +
                (
                right-left
                ) / phi;

        while (
                Math.abs(
                        right-left
                )
                >
                tolerance
        ) {

            if (
                    objective(x1)
                    <
                    objective(x2)
            ) {

                right = x2;

                x2 = x1;

                x1 =
                        right -
                        (
                        right-left
                        ) / phi;

            } else {

                left = x1;

                x1 = x2;

                x2 =
                        left +
                        (
                        right-left
                        ) / phi;
            }
        }

        return
                (
                left +
                right
                ) / 2;
    }

    public static void main(
            String[] args
    ) {

        double result =
                search(
                        -10,
                        10,
                        0.0001
                );

        System.out.println(
                "Minimum near "
                + result
        );
    }
}
