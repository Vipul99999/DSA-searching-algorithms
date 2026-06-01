namespace aubs::predictive {

template<typename T>
class AdaptiveModel
{
public:

    virtual ~AdaptiveModel() = default;

    virtual std::size_t predict(
        const T& target
    ) const = 0;
};

}