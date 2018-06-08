cmake_minimum_required(VERSION 3.10)
project(aal_solution)

set(CMAKE_CXX_STANDARD 14)

add_executable(aal_solution main.cpp Person.hpp DataSet.hpp Solver.hpp Solver.cpp SortingAlgorithm.hpp SortingAlgorithm.cpp BruteForce.cpp BruteForce.hpp RandomDataGenerator.cpp RandomDataGenerator.hpp HopcroftKarp.cpp HopcroftKarp.hpp Benchmark.cpp Benchmark.hpp include/cxxopts.hpp ArgumentsController.cpp ArgumentsController.hpp)