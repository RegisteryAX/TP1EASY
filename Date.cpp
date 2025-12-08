#include "date.h"
#include <stdexcept>  // for std::invalid_argument
#include <string>



Date::Date(int month, int day, int year) : month_(month), day_(day), year_(year) {}

int Date::month() const {
    return month_;
}

int Date::day() const {
    return day_;
}
int Date::year() const {
    return year_;
}

void Date::updateMonth(int new_month) {
    month_ = new_month;
}

void Date::updateDay(int new_day) {
    day_ = new_day;
}

void Date::updateYear(int new_year) {
    year_ = new_year;
}