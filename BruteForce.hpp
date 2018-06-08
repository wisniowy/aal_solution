//
// Created by Michał Wiśniewski on 06.06.2018.
//

#ifndef AAL_SOLUTION_BRUTEFORCE_HPP
#define AAL_SOLUTION_BRUTEFORCE_HPP


#include "DataSet.hpp"
#include "Solver.hpp"

class BruteForce : public Solver
{
public:
    explicit BruteForce(const DataSet& set);
    ~BruteForce() = default;
    bool solve() override;

private:
    void findMatching() override;

};


#endif //AAL_SOLUTION_BRUTEFORCE_HPP
