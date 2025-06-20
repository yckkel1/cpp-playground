#pragma once

#include <string>

class People {
private:
    std::string name;
    int age;
    double height;
public:
    People() = default;
    People(const std::string& name, const int& age, const double& height) : name(name), age(age), height(height) {}
    std::string get_name() const { return name; }
    int get_age() const { return age; }
    double get_height() const { return height; }
};