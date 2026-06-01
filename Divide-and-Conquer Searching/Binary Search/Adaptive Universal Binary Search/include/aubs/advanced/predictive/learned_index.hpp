namespace aubs::predictive {

template<typename T>
class LearnedIndex
{
public:

    void train(
        const std::vector<T>& data
    );

    std::size_t predict(
        const T& target
    ) const;
};

}