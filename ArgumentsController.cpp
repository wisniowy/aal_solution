//
// Created by Michał Wiśniewski on 07.06.2018.
//

#include "ArgumentsController.hpp"
#include "include/cxxopts.hpp"
#include "DataSet.hpp"
#include "Solver.hpp"
#include "SortingAlgorithm.hpp"
#include "HopcroftKarp.hpp"
#include "RandomDataGenerator.hpp"


ArgumentsController::ArgumentsController(int argc, char** argv) : argc(argc), argv(argv)
{
   std_in_buf = std::cin.rdbuf();
   std_out_buf = std::cout.rdbuf();
   redirect();
}

ArgumentsController::~ArgumentsController()
{
    std::cin.rdbuf(std_in_buf);
    std::cout.rdbuf(std_out_buf);
}

int ArgumentsController::run()
{
    try {

        cxxopts::Options options("aal_vururuk", " - example command line options");

        options.positional_help("[optional args]").show_positional_help();


        options.add_options()
                ("m1", "Get data from stdin and print result to stdout. Example -m1 <<in.txt")
                ("m2", "Generate random data and print result to stdout.")
                ("m3", "Do benchmark and print result table to stdout.")
                ("n", "Size of data set.", cxxopts::value<int>())
                ("k", "Number of problems.", cxxopts::value<int>())
                ("s,step", "How much to increment size of data set with every iteration.", cxxopts::value<int>())
                ("r,repeats", "How many times solve problem with each size of data set", cxxopts::value<int>())
                ("h,help", "Print help.");

        auto result = options.parse(argc, argv);

        if(result.count("n"))
            n = result["n"].as<int>();

        if(result.count("k"))
            k = result["k"].as<int>();

        if(result.count("s"))
            step = result["s"].as<int>();

        if(result.count("r"))
            r = result["r"].as<int>();

        if (result.count("h") || argc < 2)
        {
            std::cout << options.help({"", "Group"}) << std::endl;
            exit(0);
        }

        if(result.count("m1"))
            mode1();

        if(result.count("m2"))
            mode2();

        if(result.count("m3"))
            mode3();
    }

    catch (const cxxopts::OptionException& e)
    {
        std::cout << "error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void ArgumentsController::redirect()
{
    std::string buf;

    for(int i = 1; i < argc; ++i)
    {
        buf = argv[i];
        if(buf.find(">>") == 0)
        {
            buf.erase(0, 2);
            out.open(buf);
            std::cout.rdbuf(out.rdbuf());
        }
        else if(buf.find(">>") == 0)
        {
            buf.erase(0, 2);
            in.open(buf);
            std::cout.rdbuf(in.rdbuf());
        }
    }
}



void ArgumentsController::mode1()
{
    DataSet* data_set = DataSet::readDataFromStdin();

    Solver* solver = nullptr;

    switch(algorithm)
    {
        case sorting_algorithm:
            solver = new SortingAlgorithm(*data_set);
            break;
        case hopcroft_karp:
            solver = new HopcroftKarp(*data_set);
            break;
        default:
            solver = new SortingAlgorithm(*data_set);
    }

    solver->printResults();
    delete solver;
    delete data_set;
}

void ArgumentsController::mode2()
{
    RandomDataGenerator generator(150, 190, 30, 60, 120, 180, 20, 50);
    generator.generate(n);


    Solver* solver = nullptr;

    switch(algorithm)
    {
        case sorting_algorithm:
            solver = new SortingAlgorithm(generator.data_set);
            break;
        case hopcroft_karp:
            solver = new HopcroftKarp(generator.data_set);
            break;
        default:
            solver = new SortingAlgorithm(generator.data_set);
    }

    solver->printResults();
    delete solver;
}

void ArgumentsController::mode3()
{
    Solver* solver = nullptr;
    Benchmark benchmark;
    RandomDataGenerator generator(150, 190, 30, 60, 120, 180, 20, 50);
    int amount = n;

    for(int i = 0; i < k; ++i)
    {
        benchmark.startAveraging();
        for(int j = 0; j < r; ++j)
        {
            generator.generate(amount);

            switch(algorithm)
            {
                case sorting_algorithm:
                    solver = new SortingAlgorithm(generator.data_set);
                    break;
                case hopcroft_karp:
                    solver = new HopcroftKarp(generator.data_set);
                    break;
                default:
                    solver = new SortingAlgorithm(generator.data_set);
            }

            benchmark.start();
            solver->solve();
            benchmark.stop();

            delete solver;
        }

        amount += step;

        benchmark.stopAveraging();
    }

    benchmark.printResults(n, step, algorithm);
}