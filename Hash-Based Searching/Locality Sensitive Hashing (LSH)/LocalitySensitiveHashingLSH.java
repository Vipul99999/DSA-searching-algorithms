/*
    LocalitySensitiveHashingLSH.java
    Cosine Similarity LSH using Random Hyperplanes
*/

public class LocalitySensitiveHashingLSH {

    private static final int DIMENSIONS = 4;
    private static final int HYPERPLANES = 3;

    static class Vector {

        double[] values;

        Vector(double... values) {
            this.values = values;
        }
    }

    static double dotProduct(
        Vector a,
        Vector b
    ) {

        double result = 0.0;

        for (
            int i = 0;
            i < DIMENSIONS;
            i++
        ) {

            result +=
                a.values[i]
                * b.values[i];
        }

        return result;
    }

    static int computeHash(
        Vector point,
        Vector[] planes
    ) {

        int hash = 0;

        for (
            int i = 0;
            i < HYPERPLANES;
            i++
        ) {

            if (
                dotProduct(
                    point,
                    planes[i]
                ) >= 0
            ) {

                hash |= (1 << i);
            }
        }

        return hash;
    }

    public static void main(
        String[] args
    ) {

        Vector[] hyperplanes = {

            new Vector(
                1,0,-1,0
            ),

            new Vector(
                0,1,0,-1
            ),

            new Vector(
                1,1,1,1
            )
        };

        Vector point1 =
            new Vector(
                2,3,1,0
            );

        Vector point2 =
            new Vector(
                2,2,1,1
            );

        int hash1 =
            computeHash(
                point1,
                hyperplanes
            );

        int hash2 =
            computeHash(
                point2,
                hyperplanes
            );

        System.out.println(
            "Point1 Hash: "
            + hash1
        );

        System.out.println(
            "Point2 Hash: "
            + hash2
        );

        if (hash1 == hash2)
            System.out.println(
                "Likely Similar"
            );
        else
            System.out.println(
                "Likely Different"
            );
    }
}
