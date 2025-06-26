#include "include/people_analytics.hpp"
#include <iostream>
#include <map>
#include "time_slot.hpp"
#include <unordered_map>

int main() {

    PeopleAnalytics pa;
    pa.add("Alice", 25, 1.72);
    pa.add("Bob", 17, 1.80);
    pa.add("Carol", 30, 1.60);
    pa.add("Dave", 22, 1.90);
    auto names = pa.get_names_of_tall_adults(1.70);
    for(auto& name : names) {
        std::cout << name << "\t" << std::endl;
    }

    std::vector<int> numbers = {-3, -2, -1, 0, 1, 2, 3, 4};
    std::vector<int> evens;

    std::ranges::copy_if(
        numbers,                           // input range
        std::back_inserter(evens),         // output iterator
        [](int abs_val) { return abs_val % 2 == 0; },  // predicate on projected value
        [](int x) { return std::abs(x); }              // projection
    );

    std::map<TimeSlot, int> time_slot_map;
    time_slot_map[{9, 10}] = 1;
    time_slot_map[{11, 13}] = 4;
    time_slot_map[{9, 11}] = 2;
    time_slot_map[{10, 11}] = 3;
    for(auto& [key, val] : time_slot_map) {
        std::cout << "start time : " << key.start_time << " end time : " << key.end_time 
        << " val : " << val << std::endl;
    }
    std::cout << std::endl;
    std::unordered_map<TimeSlot, int, TimeSlotHasher> time_slot_map_2;
    time_slot_map_2[{9, 10}] = 1;
    time_slot_map_2[{11, 13}] = 4;
    time_slot_map_2[{9, 11}] = 2;
    time_slot_map_2[{10, 11}] = 3;
    for(auto& [key, val] : time_slot_map_2) {
        std::cout << "start time : " << key.start_time << " end time : " << key.end_time 
        << " val : " << val << std::endl;
    }
}
