#pragma once

#include <functional>

struct TimeSlot {
    int start_time;
    int end_time;

    // bool operator< (const TimeSlot& other_slot) const {
    //     return start_time != other_slot.start_time
    //             ? start_time < other_slot.start_time 
    //             : end_time < other_slot.end_time;
    // }

    // bool operator== (const TimeSlot& other_slot) const = default;

    auto operator<=> (const TimeSlot& other_slot) const = default;
};

struct TimeSlotHasher {
    std::size_t operator() (const TimeSlot& slot) const {
        return std::hash<int>{}(slot.start_time) ^ (std::hash<int>{}(slot.end_time) << 1);
    }
};