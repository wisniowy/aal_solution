//
// Created by Michał Wiśniewski on 07.06.2018.
//

#ifndef AAL_SOLUTION_HOPCROFTKARP_HPP
#define AAL_SOLUTION_HOPCROFTKARP_HPP


#include "Solver.hpp"

class HopcroftKarp : public Solver{
private:
    std::vector<std::vector<int>> graph;
    std::vector<int> distance;
public:
    explicit HopcroftKarp(const DataSet& set);
    bool solve() override;
    void printResults() override;

private:
    void findMatching() override;
    bool buildGraph();
    static bool compare(const Person& man, const Person& woman);
    bool bfs();
    bool dfs();
};


#endif //AAL_SOLUTION_HOPCROFTKARP_HPP
