//
// Created by Michał Wiśniewski on 25.05.2018.
//

#ifndef AAL_SOLUTION_SOLVER_HPP
#define AAL_SOLUTION_SOLVER_HPP

#include "DataSet.hpp"


class Solver
{
protected:
    typedef std::pair<Person, Person> Pair;
    const DataSet data_set;
    const size_t SIZE_OF_VECS;
    std::vector<int> matching;

public:
    explicit Solver(const DataSet& set);
    virtual ~Solver() = default;
    virtual void printResults();
    virtual bool solve() = 0;


protected:
    virtual void findMatching() = 0;
};



#endif //AAL_SOLUTION_SOLVER_HPP
