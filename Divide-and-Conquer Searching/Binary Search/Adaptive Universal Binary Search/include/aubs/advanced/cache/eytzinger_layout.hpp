namespace aubs::cache {

template<typename T>
class EytzingerLayout
{
public:

    static std::vector<T>
    build(
        const std::vector<T>& sorted
    );
};

}