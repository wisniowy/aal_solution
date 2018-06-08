//
// Created by Michał Wiśniewski on 25.05.2018.
//

#include <iostream>
#include "SortingAlgorithm.hpp"

SortingAlgorithm::SortingAlgorithm(const DataSet& set) : Solver(set)
{
    std::vector<int> temp(SIZE_OF_VECS, -1);
    matching = temp;
}

bool SortingAlgorithm::solve()
{
    findMatching();

    for(int i = 0; i < matching.size(); ++i) {
        if (matching[i] == -1)
            return false;
    }
    return true;
}

void SortingAlgorithm::findMatching()
{
    std::vector<Person> men(data_set.men);
    std::vector<Person> women(data_set.women);
    std::vector<bool> matched_women(data_set.men.size(), false);
    std::vector<int> temp(SIZE_OF_VECS, -1);
    matching = temp;

    std::sort(men.begin(), men.end());
    std::sort(women.begin(), women.end());

    for(int i = 0; i < men.size(); ++i)
    {
        int max_d = -1;
        int woman_idx = -1;

        for(int j = 0; j < women.size(); ++j )
        {


            if(men[i].height <= women[j].height)
                break;

            if(women[j].diameter < men[i].diameter && women[j].diameter > max_d && !matched_women[j])
            {
                max_d = women[j].diameter;
                woman_idx = j;
            }

        }

        if(woman_idx >= 0)
        {
            matching[i] = woman_idx;
            matched_women[woman_idx] = true;
        }

        else
            break;
    }

}

