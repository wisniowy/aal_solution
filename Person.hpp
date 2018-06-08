//
// Created by Michał Wiśniewski on 25.05.2018.
//

#ifndef AAL_SOLUTION_PERSON_HPP
#define AAL_SOLUTION_PERSON_HPP

#include <utility>

typedef struct Person{
     long p_id;
     int height;
     int diameter;

    Person(const long id, const int h, const int d) : p_id(id), height(h), diameter(d) {};

    bool operator<(const Person& other) const
    {
        return std::pair<int, int>(height, diameter) < std::pair<int, int>(other.height, other.diameter);
    }


} Person;

#endif //AAL_SOLUTION_PERSON_HPP
