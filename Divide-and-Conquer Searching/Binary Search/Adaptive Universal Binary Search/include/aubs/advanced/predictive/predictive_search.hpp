namespace aubs::predictive {

template<typename T>
class PredictiveSearch
{
public:

    static int search(
        const std::vector<T>& data,
        const T& target
    );
};

}