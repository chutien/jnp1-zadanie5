#include "person.h"

Adult::Adult(std::string &name, Price savings = Price())
        : name(name), savings(savings) {}

Price Adult::getSavings() {
    return Price();
}

std::string Person::getName() {
    return name;
}

Child::Child(std::string &name) : name(name) {}