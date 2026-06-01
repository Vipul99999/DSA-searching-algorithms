namespace aubs::branchless {

template<typename T>
class BranchlessLowerBound
{
public:

    static std::size_t search(
        const T* data,
        std::size_t size,
        const T& target
    );
};

}