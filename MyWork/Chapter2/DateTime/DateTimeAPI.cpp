#include "DateTimeAPI.h"
#include <iostream>

// Implementations for Year
Year::Year(int year) : year_(year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        leap_ = true;
    } else {
        leap_ = false;
    }
}

bool Year::isLeap() const { return leap_; }

// Implementations for Month
Month::Month(const Year& year, int month) : month_(month) {
    // Your logic here
}

int Month::getDays() const { return days_; }

// Implementations for Day
Day::Day(int day) : day_(day) {}

// Implementations for Date
Date::Date(int year, int month, int day) {
    year_ = new Year(year);
    month_ = new Month(*year_, month);
    day_ = new Day(day);
}

Date::~Date() {
    delete year_;
    delete month_;
    delete day_;
}

void Date::print() const {
    std::cout << "Year: " << year_->isLeap() << std::endl;
    std::cout << "Month: " << month_->getDays() << std::endl;
}

// Implementations for Time1
Time1::Time1(int year, int month, int day, int hour, int minute, int second)
    : Date(year, month, day), hour_(hour), minute_(minute), second_(second) {}

void Time1::print() const {
    Date::print();
    std::cout << "Time: " << hour_ << ":" << minute_ << ":" << second_ << std::endl;
}
