#include "people.hpp"
#include <ostream>

std::ostream& operator<< (std::ostream& os, const People& people) {
    os << "Name: " << people.get_name() << '\t';
    os << "Age: " << people.get_age() << '\t';
    os << "Height: " << people.get_height() << std::endl;
    return os;
}
