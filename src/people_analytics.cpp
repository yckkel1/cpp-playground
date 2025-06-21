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

std::map<std::string, std::vector<std::string>> PeopleAnalytics::get_age_grouped_names() {
    // "Child" -> age < 18
    // "Adult" -> 18-64
    // "Senior" -> 65+
    std::map<std::string, std::vector<std::string>> group_map;
    get_age_grouped_names_helper(group_map, "Child", 0, 17);
    get_age_grouped_names_helper(group_map, "Adult", 18, 64);
    get_age_grouped_names_helper(group_map, "Senior", 65, 200); // arbitrary big enough age as cap
    return group_map;
}

void PeopleAnalytics::get_age_grouped_names_helper(std::map<std::string, std::vector<std::string>>& group_map, const std::string& group_name, int age_lower_bound, int age_higher_bound) {
    auto view_filtered_by_age = people_arr | std::views::filter([age_lower_bound, age_higher_bound](const std::unique_ptr<People>& people) {
        return people->get_age() >= age_lower_bound && people->get_age() <= age_higher_bound;
    });
    auto names_filtered_by_age = view_filtered_by_age | std::views::transform([](const std::unique_ptr<People>& people) {
        return people->get_name();
    });
    group_map[group_name] = std::vector<std::string> (names_filtered_by_age.begin(), names_filtered_by_age.end());
    std::ranges::sort(group_map[group_name]);
}