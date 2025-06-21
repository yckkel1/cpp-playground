#pragma once

#include "people.hpp"
#include <memory>
#include <vector>
#include <map>

class PeopleAnalytics {
private:
    std::vector<std::unique_ptr<People>> people_arr;
    void get_age_grouped_names_helper(std::map<std::string, std::vector<std::string>>& group_map, const std::string& group_name, int age_lower_bound, int age_higher_bound);
public:
    PeopleAnalytics() = default;
    void add(const std::string& name, int age, double height); // Add this to people_arr internally
    std::vector<std::string> get_names_of_tall_adults(double min_height); // return names of all people taller than min_height
    std::map<std::string, std::vector<std::string>> get_age_grouped_names(); // map people to different age groups 
};