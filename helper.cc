#include <iomanip>
#include <random>
#include "helper.h"

namespace {
    int HOURS = 24;
    int MINUTES = 60;
    std::mersenne_twister_engine mte(0);
    std::uniform_int_distribution<int> uid(0, std::numeric_limits<int>::max());
}

Price::Price(int n) : value(n){}

Price Price::operator+(const Price &other) const {
    return Price(value + other.value);
}

bool Price::operator<(const Price &other) const {
    return value < other.value;
}

const Price &Price::operator-=(const Price &other) {
    value -= other.value;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Price &price) {
    os << price.value << " PLN";
    return os;
}

Date::Date(int day, int hour, int minute) {
    totalMinutes = day * MINUTES * HOURS + hour * MINUTES + minute;
}

Date &Date::operator++() {
    totalMinutes++;
    return *this;
}

int Date::operator-(const Date &other) const {
    return totalMinutes - other.totalMinutes;
}

bool Date::operator<(const Date &other) const {
    return totalMinutes < other.totalMinutes;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "December, "  << std::setfill('0') << std::setw(2)
        << date.totalMinutes/MINUTES/HOURS << ", " << std::setw(2)
        << date.totalMinutes%(HOURS*MINUTES) / MINUTES << ":" << std::setw(2)
        << date.totalMinutes%MINUTES;
    return os;
}

int randomNumber() {
    return uid(mte);
}



