//
// Created by Michał Wiśniewski on 06.06.2018.
//

#include <iostream>
#include "BruteForce.hpp"

BruteForce::BruteForce(const DataSet &set) : Solver(set) {}



bool BruteForce::solve()
{
    if(matching.empty())
        findMatching();

    for(int i = 0; i < matching.size(); ++i)
        if(matching[i] == -1)
            return false;

    return true;
}

void BruteForce::findMatching()
{

    std::vector<int> permutations(data_set.SIZE_OF_VECS, 0);
    std::vector<int> temp(data_set.SIZE_OF_VECS, -1);
    matching = temp;

    for(int i = 0; i < permutations.size(); ++i)
        permutations[i] = i;


    bool matching_possible;

    do {

        matching_possible = true;

        for(int i = 0; i < permutations.size(); ++i)
        {
            Person man = data_set.men[i];
            Person woman = data_set.women[permutations[i]];

            if(woman.height >= man.height || woman.diameter >= man.diameter)
                matching_possible = false;

        }

        if(matching_possible)
        {
            matching = permutations;
            break;
        }

    } while(std::next_permutation(permutations.begin(), permutations.end()));

}


