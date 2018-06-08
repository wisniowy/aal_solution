#include <iostream>
#include <vector>
#include "Person.hpp"
#include "DataSet.hpp"
#include "Solver.hpp"
#include "SortingAlgorithm.hpp"
#include "BruteForce.hpp"
#include "RandomDataGenerator.hpp"
#include "HopcroftKarp.hpp"
#include "include/cxxopts.hpp"
#include "ArgumentsController.hpp"
#include <chrono>

int main(int argc, char **argv) {

    RandomDataGenerator generator(150, 190, 30, 60, 120, 180, 20, 50);




//    for(int i = 0; i < 100; ++i)
//    {
//        generator.generate(40);
//
//        Solver* solver3 = new HopcroftKarp(generator.data_set);
//        Solver* solver2 = new SortingAlgorithm(generator.data_set);
//        Solver* solver = new BruteForce(generator.data_set);
//
//        solver2->solve();
//        solver3->solve();
//
//
////        if(solver->solve() != solver3->solve())
////            std::cout << "HK źle\n";
////        if(solver->solve() != solver2->solve())
////            std::cout << "HK źle\n";
//
//        delete solver;
//        delete solver2;
//        delete solver3;
//
//    }

    ArgumentsController controller(argc, argv);
    controller.run();

    return 0;
}