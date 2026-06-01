namespace aubs::simd {

template<typename T>
class SIMDSearch
{
public:

    static int search(
        const T* data,
        std::size_t size,
        const T& target
    );
};

}