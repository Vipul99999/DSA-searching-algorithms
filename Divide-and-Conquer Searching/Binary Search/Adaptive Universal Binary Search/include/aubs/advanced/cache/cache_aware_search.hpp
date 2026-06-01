namespace aubs::cache {

template<typename T>
class CacheAwareSearch
{
public:

    static int search(
        const std::vector<T>& data,
        const T& target
    );
};

}