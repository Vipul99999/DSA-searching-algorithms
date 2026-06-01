namespace aubs::branchless {

template<typename T>
class BranchlessBinarySearch
{
public:

    static int search(
        const T* data,
        std::size_t size,
        const T& target
    );
};

}