#pragma once

#include "people.hpp"
#include <memory>
#include <vector>

class PeopleAnalytics {
private:
    std::vector<std::unique_ptr<People>> people_arr;
public:
    PeopleAnalytics() = default;
    void add(const std::string& name, int age, double height); // Add this to people_arr internally
    std::vector<std::string> get_names_of_tall_adults(double min_height); // return names of all people taller than min_height
};