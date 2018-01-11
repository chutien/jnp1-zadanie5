#include "person.h"

Person::Person(const std::string& name) : name(name) {}

std::string Person::getName() const {
    return name;
}

Adult::Adult(const std::string& name, Price savings)
        : Person(name), savings(savings) {}

void Adult::update(Observable &observable) const {
    std::cout << "We have new decoration!" << std::endl;
    std::cout << "Total cost is " << observable.getPrice() << "." << std::endl;
}

void Adult::buyDecoration(const Decoration& decoration) {
    savings -= decoration.getPrice();
}

Price Adult::getSavings() const {
    return savings;
}

Child::Child(const std::string& name) : Person(name) {}

void Child::update(Observable &observable) const {
    std::cout << "Wow!" << std::endl;
    observable.doOperationOnLast(std::cout);
}