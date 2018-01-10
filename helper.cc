#include "helper.h"
#include <iomanip>
#include <random>

namespace {
    int HOURS = 24;
    int MINUTES = 60;
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
        << date.totalMinutes/MINUTES/HOURS << ", "
        << date.totalMinutes%(HOURS*MINUTES) / MINUTES << ":"
        << std::setfill('0') << std::setw(2)
        << date.totalMinutes%MINUTES;
    return os;
}

int randomNumber() {
    static std::mt19937 mte(0);
    static std::uniform_int_distribution<int> uid(0, std::numeric_limits<int>::max());
    return uid(mte);
}

Date& currentDate() {
    static Date currentDate(18, 16, 00);
    return currentDate;
}


Observable::obsIterator
Observable::attachObserver(const std::shared_ptr<Observer> &observer) {
    observers.push_back(observer);
    return --observers.end();
}

void Observable::detachObserver(Observable::obsIterator it) {
    observers.erase(it);
}

void Observable::notify() {
    for (auto &observer : observers) {
        observer->update(*this);
    }
}
