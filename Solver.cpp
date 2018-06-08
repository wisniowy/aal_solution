//
// Created by Michał Wiśniewski on 25.05.2018.
//

#include <iostream>
#include "Solver.hpp"

Solver::Solver(const DataSet& set) : data_set(set), SIZE_OF_VECS(data_set.SIZE_OF_VECS) {}

void Solver::printResults()
{
    if(!solve())
    {
        std::cout << "MATCHING NOT FOUND" << std::endl;
        return;
    }

    for(int i = 0; i < matching.size(); ++i)
    {
        Person man = data_set.men[i];
        Person woman = data_set.women[matching[i]];

        std::cout << "M " << man.p_id << " (" << man.height << ", " << man.diameter << ")";
        std::cout << "  --  ";
        std::cout << "W " << woman.p_id << " (" << woman.height << ", " << woman.diameter << ")\n";

    }
}