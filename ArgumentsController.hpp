//
// Created by Michał Wiśniewski on 07.06.2018.
//

#ifndef AAL_SOLUTION_ARGUMENTSCONTROLLER_HPP
#define AAL_SOLUTION_ARGUMENTSCONTROLLER_HPP


#include <fstream>
#include "Benchmark.hpp"

class ArgumentsController {
private:
    int argc;
    char** argv;
    Algorithm algorithm = sorting_algorithm;
    int n = 100;
    int k = 10;
    int step = 50;
    int r = 10;
    std::streambuf* std_in_buf = nullptr;
    std::streambuf* std_out_buf = nullptr;
    std::ifstream in;
    std::ofstream out;


public:
    ArgumentsController(int argc, char** argv);
    ~ArgumentsController();
    int run();


private:
    void redirect();
    void mode1();
    void mode2();
    void mode3();
};


#endif //AAL_SOLUTION_ARGUMENTSCONTROLLER_HPP
