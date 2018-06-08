//
// Created by Michał Wiśniewski on 25.05.2018.
//

#ifndef AAL_SOLUTION_SORTINGMETHOD_HPP
#define AAL_SOLUTION_SORTINGMETHOD_HPP

#include "Solver.hpp"

class SortingAlgorithm : public Solver
{
public:
    explicit SortingAlgorithm(const DataSet& set);
    ~SortingAlgorithm() = default;
    bool solve() override;

private:
    void findMatching() override;

};

#endif //AAL_SOLUTION_SORTINGMETHOD_HPP
