//
// Created by Michał Wiśniewski on 07.06.2018.
//

#ifndef AAL_SOLUTION_BENCHMARK_HPP
#define AAL_SOLUTION_BENCHMARK_HPP

#include <chrono>
#include <vector>

typedef enum
{
    hopcroft_karp = 1,
    sorting_algorithm = 2

} Algorithm;


class Benchmark {

private:
    std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point end;
    std::vector<long double> times;
    std::vector<long double> averaged_times;

public:
    Benchmark() = default;
    void start();
    void stop();
    void startAveraging();
    void stopAveraging();
    void printResults(int n, int step, Algorithm algorithm);

};


#endif //AAL_SOLUTION_BENCHMARK_HPP
