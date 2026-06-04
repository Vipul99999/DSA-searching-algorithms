class PerfectHashing:

    def __init__(self):

        self.data = set()

    def build(
        self,
        keys
    ):

        for key in keys:
            self.data.add(
                key
            )

    def search(
        self,
        key
    ):

        return (
            key
            in
            self.data
        )


table = PerfectHashing()

table.build(
    [
        10,
        25,
        42,
        60
    ]
)

print(
    table.search(
        42
    )
)
