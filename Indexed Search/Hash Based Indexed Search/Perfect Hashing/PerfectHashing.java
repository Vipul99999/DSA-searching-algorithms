import java.util.HashSet;

public class PerfectHashing {

    private HashSet<Integer>
        table =
        new HashSet<>();

    public void build(
        int[] keys
    ) {

        for (
            int key :
            keys
        )
            table.add(
                key
            );
    }

    public boolean search(
        int key
    ) {

        return table.contains(
            key
        );
    }

    public static void main(
        String[] args
    ) {

        PerfectHashing p =
            new PerfectHashing();

        p.build(
            new int[]{
                10,
                42,
                60
            }
        );

        System.out.println(
            p.search(
                42
            )
        );
    }
}
