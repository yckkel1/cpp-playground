#include "people_analytics.hpp"
#include <ranges>

void PeopleAnalytics::add(const std::string& name, int age, double height) {
    people_arr.emplace_back(std::make_unique<People>(name, age, height));
}

std::vector<std::string> PeopleAnalytics::get_names_of_tall_adults(double min_height) {
    auto taller_people_view = people_arr | std::views::filter([min_height](const std::unique_ptr<People>& people) {
        return people->get_height() >= min_height;
    });
    auto name_view = taller_people_view | std::views::transform([](const std::unique_ptr<People>& people) {
        return people->get_name();
    });
    return std::vector<std::string>(name_view.begin(), name_view.end());
}