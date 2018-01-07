#include "person.h"

// Person
std::string Person::getName() const {
    return name;
}

// Adult
Adult::Adult(std::string &name, Price savings = Price())
        : name(name), savings(savings) {}

void Adult::buyDecoration(const std::shared_ptr<Decoration> &decoration) {

}

Price Adult::getSavings() {
    return savings;
}



Child::Child(std::string &name) : name(name) {}