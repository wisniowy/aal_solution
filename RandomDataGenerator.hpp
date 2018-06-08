//
// Created by Michał Wiśniewski on 06.06.2018.
//

#ifndef AAL_SOLUTION_RANDOMDATAGENERATOR_HPP
#define AAL_SOLUTION_RANDOMDATAGENERATOR_HPP


#include "DataSet.hpp"

struct RandomDataGenerator {

private:
    int min_man_height;
    int max_man_height;
    int min_woman_height;
    int max_woman_height;
    int min_man_diameter;
    int max_man_diameter;
    int min_woman_diameter;
    int max_woman_diameter;
    std::vector<Person> men;
    std::vector<Person> women;

public:
    DataSet data_set;

    RandomDataGenerator(int min_m_h, int max_m_h, int min_m_d, int max_m_d,
                                             int min_w_h, int max_w_h, int min_w_d, int max_w_d)
    {
        min_man_height = min_m_h;
        max_man_height = max_m_h;
        min_man_diameter = min_m_d;
        max_man_diameter = max_m_d;
        min_woman_height = min_w_h;
        max_woman_height = max_w_h;
        min_woman_diameter = min_w_d;
        max_woman_diameter = max_w_d;

        srand((unsigned int) time(nullptr));
    }


    void generate(const size_t amount)
    {
        men.clear();
        women.clear();
        men.reserve(amount);
        women.reserve(amount);

        for(int i = 0; i < amount; ++i)
        {
            int m_height = rand() % (max_man_height + 1 - min_man_height) + min_man_height;
            int m_diameter = rand() % (max_man_diameter + 1 - min_man_diameter) + min_man_diameter;

            men.emplace_back(i, m_height, m_diameter);

            int w_height = rand() % (max_woman_height + 1 - min_woman_height) + min_woman_height;
            int w_diameter = rand() % (max_woman_diameter + 1 - min_woman_diameter) + min_woman_diameter;

            women.emplace_back(i, w_height, w_diameter);
        }

         data_set.loadVecs(men, women);



    }

};


#endif //AAL_SOLUTION_RANDOMDATAGENERATOR_HPP
