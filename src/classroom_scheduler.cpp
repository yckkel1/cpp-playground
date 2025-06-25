#include "classroom_scheduler.hpp"
#include <algorithm>
#include <ranges>

using CoursePtr = std::unique_ptr<Course>;

void ClassroomScheduler::schedule_course(std::string name, int start_time, int end_time, int enrolled) {
    courses.emplace_back(std::make_unique<Course>(name, start_time, end_time, enrolled));
}

std::vector<std::string> ClassroomScheduler::get_conflicting_courses(int query_start, int query_end) const{
    auto conflicting_course_view = courses | std::views::filter([query_start, query_end](const CoursePtr& ptr) {
        return ptr->get_start_time() < query_end && ptr->get_end_time() > query_start;
    });
    auto conflicting_course_names = conflicting_course_view | std::views::transform([](const CoursePtr& ptr) {
        return ptr->get_name();
    });
    return std::vector<std::string>(conflicting_course_names.begin(), conflicting_course_names.end());
}

// Group courses by student count:
// 0-20 -> 0
// 21-50 -> 1
// 51+ -> 2
std::map<int, std::vector<std::string>> ClassroomScheduler::group_courses_by_enrollment_bucket() const{
    std::map<int, std::vector<std::string>> courses_by_enrollment_bucket;
    for(auto& course : courses) {
        if(course->get_enrolled() >= 0 && course->get_enrolled() <= 20) {
            courses_by_enrollment_bucket[0].push_back(course->get_name());
        }
        else if(course->get_enrolled() <= 50) {
            courses_by_enrollment_bucket[1].push_back(course->get_name());
        }
        else {
            courses_by_enrollment_bucket[2].push_back(course->get_name());
        }
    }
    return courses_by_enrollment_bucket;
}

bool ClassroomScheduler::is_available_for_new_course(int start, int end) const {
    return std::none_of(courses.begin(), courses.end(), [start, end](const CoursePtr& course) {
        return course->get_start_time() < end && course->get_end_time() > start;
    });
}