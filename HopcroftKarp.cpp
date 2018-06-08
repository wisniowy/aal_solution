//
// Created by Michał Wiśniewski on 07.06.2018.
//

#include <iostream>
#include <queue>
#include "HopcroftKarp.hpp"


HopcroftKarp::HopcroftKarp(const DataSet &set) : Solver(set), graph(SIZE_OF_VECS * 2, std::vector<int>()),
                                                 distance(SIZE_OF_VECS * 2, -1)
{
    std::vector<int> temp((SIZE_OF_VECS * 2), -1);
    matching = temp;
}

bool HopcroftKarp::solve() {

    if(!buildGraph())
        return false;

    findMatching();

    for(int i = 0; i < matching.size(); ++i)
    {
        if(matching[i] == -1)
            return false;
    }

    return true;
}

void HopcroftKarp::findMatching() {

    std::fill(matching.begin(), matching.end(), -1);
    std::vector<bool> visited_humans(data_set.men.size() + data_set.women.size() , false);
    std::vector<int> matching_path(data_set.men.size() + data_set.women.size(), -1);

    std::queue<int> queue;

    for(int v = 0; v < SIZE_OF_VECS * 2; ++v)
    {
        if(matching[v] == -1 && v > SIZE_OF_VECS - 1) {
            std::fill(visited_humans.begin(), visited_humans.end(), false);


            while (!queue.empty())
                queue.pop();

            visited_humans[v] = true;
            matching_path[v] = -1;
            queue.push(v);


            while (!queue.empty()) {
                int x = queue.front();
                queue.pop();

                if (x < SIZE_OF_VECS) {
                    if (matching[x] == -1) {
                        while (matching_path[x] > -1) {
                            if (x < SIZE_OF_VECS) {
                                matching[x] = matching_path[x];
                                matching[matching_path[x]] = x;
                            }

                            x = matching_path[x];
                        }
                        break;
                    } else {
                        matching_path[matching[x]] = x;
                        visited_humans[matching[x]] = true;
                        queue.push(matching[x]);
                    }
                } else {
                    std::vector<int> temp = graph[x];

                    for (int i = 0; i < temp.size(); ++i) {
                        int y = temp[i];

                        if (!visited_humans[y]) {
                            visited_humans[y] = true;
                            matching_path[y] = x;
                            queue.push(y);
                        }
                    }
                }
            }

        }
    }
}

bool HopcroftKarp::buildGraph()
{
    for(int i = 0; i < SIZE_OF_VECS; ++i)
        for(int j = 0; j < SIZE_OF_VECS; ++j)
        {
            if(compare(data_set.men[i], data_set.women[j]))
            {
                graph[i].push_back(j + SIZE_OF_VECS);
                graph[j + SIZE_OF_VECS].push_back(i);
            }
        }

    for(const auto& i : graph)
        if(i.empty())
            return false;

    return true;
}

bool HopcroftKarp::compare(const Person &man, const Person &woman)
{
    return man.height > woman.height && man.diameter > woman.diameter;
}

void HopcroftKarp::printResults() {

    if(!solve())
    {
        std::cout << "MATCHING NOT FOUND" << std::endl;
        return;
    }

    for(int i = 0; i < SIZE_OF_VECS; ++i)
    {
        Person man = data_set.men[i];
        Person woman = data_set.women[matching[i] - SIZE_OF_VECS];

        std::cout << "M " << man.p_id << " (" << man.height << ", " << man.diameter << ")";
        std::cout << "  --  ";
        std::cout << "W " << woman.p_id << " (" << woman.height << ", " << woman.diameter << ")\n";

    }
}

