#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "course.hpp"

class ClassroomScheduler {
private:
    std::vector<std::unique_ptr<Course>> courses;
public:
    ClassroomScheduler() = default;
    // Adds a course to schedule
    void schedule_course(std::string name, int start_time, int end_time, int enrolled);
    // Return names of all scheduled courses that overlap with [query_start, query_end)
    std::vector<std::string> get_conflicting_courses(int query_start, int query_end) const;
    // Group courses by student count:
    // 0-20 -> 0
    // 21-50 -> 1
    // 51+ -> 2
    std::map<int, std::vector<std::string>> group_courses_by_enrollment_bucket() const;
    bool is_available_for_new_course(int start, int end) const;
};