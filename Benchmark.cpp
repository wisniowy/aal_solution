//
// Created by Michał Wiśniewski on 07.06.2018.
//

#include <iostream>
#include <array>
#include <cmath>
#include <iomanip>
#include "Benchmark.hpp"

void Benchmark::start()
{
    begin = std::chrono::high_resolution_clock::now();
}

void Benchmark::stop()
{
    end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<long double, std::milli> duration = end - begin;
    times.push_back(duration.count());
}

void Benchmark::startAveraging()
{
    times.clear();
}


void Benchmark::stopAveraging()
{
    unsigned long repetitions = times.size();

    long double sum = 0;

    for(const auto& time : times)
        sum += time;

    long double average = sum / repetitions;

    averaged_times.push_back(average);
}

void Benchmark::printResults(int n, int step, Algorithm algorithm)
{
    std::cout << "n" << ";" << "t(n)" << ";" <<  ";" << std::setw(12) <<  ";" "\r\n";


    std::vector<double> estimated_times(averaged_times.size(), 0);


    for(int i = 0; i < estimated_times.size(); ++i)
    {
        int local_n = n + i * step;

        switch(algorithm)
        {
            case hopcroft_karp:
                estimated_times[i] = local_n * local_n * sqrt(2 * local_n);
                break;
            case sorting_algorithm:
                estimated_times[i] = local_n * local_n;
                break;
            default:
                break;
        }

        estimated_times[i] /= 1000;
    }

    long double q = 0;

    for(int i = 0; i < estimated_times.size(); ++i)
    {
        int local_n = n + i * step;

        q = (averaged_times[i] * estimated_times[averaged_times.size() / 2])
                / (estimated_times[i] * averaged_times[averaged_times.size() / 2]);

          std::cout  << local_n << ";" << averaged_times[i] << ";";
          std::cout << estimated_times[i] << ";" << q << "\r\n";

    }
}