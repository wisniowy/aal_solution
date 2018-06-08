//
// Created by Michał Wiśniewski on 25.05.2018.
//

#ifndef AAL_SOLUTION_DATASET_HPP
#define AAL_SOLUTION_DATASET_HPP


#include <vector>
#include "Person.hpp"

typedef struct DataSet{

    std::vector<Person> women;
    std::vector<Person> men;
    size_t SIZE_OF_VECS;


    DataSet() : SIZE_OF_VECS(0) {};
    DataSet(const std::vector<Person> m, const std::vector<Person> w) : SIZE_OF_VECS(m.size()), men(m), women(w){};

    void loadVecs(const std::vector<Person> m, const std::vector<Person> w)
    {
        men = m;
        women = w;
        SIZE_OF_VECS = m.size();
    }


    static DataSet* readDataFromStdin()
    {
        size_t men_amount;
        size_t women_amount;
        int height_temp;
        int diameter_temp;
        std::vector<Person> men;
        std::vector<Person> women;

        std::cin >> men_amount;

        men.reserve(men_amount);

        for(int i = 0; i < men_amount; ++i)
        {
            std::cin >> height_temp;
            std::cin >> diameter_temp;

            men.emplace_back(i, height_temp, diameter_temp);
        }


        std::cin >> women_amount;

        women.reserve(women_amount);

        for(int i = 0; i < women_amount; ++i)
        {
            std::cin >> height_temp;
            std::cin >> diameter_temp;

            women.emplace_back(i, height_temp, diameter_temp);
        }

        return new DataSet(men, women);
    }



} DataSet;


#endif //AAL_SOLUTION_DATASET_HPP
