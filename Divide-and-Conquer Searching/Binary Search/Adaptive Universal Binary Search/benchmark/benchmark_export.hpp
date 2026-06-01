#ifndef AUBS_BENCHMARK_EXPORT_HPP
#define AUBS_BENCHMARK_EXPORT_HPP

#include <fstream>

namespace aubs::benchmark {

class BenchmarkExporter
{
public:

    template<typename Container>
    static void exportCSV(
        const Container& results,
        const std::string& filename
    )
    {
        std::ofstream file(filename);

        file
        << "Algorithm,"
        << "DatasetSize,"
        << "AverageNS,"
        << "Throughput\n";

        for(const auto& r : results)
        {
            file
            << r.algorithm << ","
            << r.datasetSize << ","
            << r.averageNanoseconds << ","
            << r.throughput
            << "\n";
        }
    }
};

}

#endif