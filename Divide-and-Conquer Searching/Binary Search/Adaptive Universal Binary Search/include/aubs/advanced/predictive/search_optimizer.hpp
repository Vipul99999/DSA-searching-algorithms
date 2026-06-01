namespace aubs::predictive {

enum class Strategy
{
    Binary,
    SIMD,
    CacheAware,
    Branchless,
    Predictive
};

class SearchOptimizer
{
public:

    template<typename T>
    static Strategy choose(
        const std::vector<T>& data
    );
};

}