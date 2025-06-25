#pragma once

#include <string>

class Course {
private:
    std::string name;
    int start_time; // 0-23
    int end_time; // 1-24; strictly > start_time
    int enrolled; // number of students enrolled
public:
    Course() = default;
    Course(std::string name, int start_time, int end_time, int enrolled) : name(name), start_time(start_time), end_time(end_time), enrolled(enrolled) {}
    std::string get_name() const { return name; }
    int get_start_time() const { return start_time; }
    int get_end_time() const { return end_time; }
    int get_enrolled() const { return enrolled; }
};