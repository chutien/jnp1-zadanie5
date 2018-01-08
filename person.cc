#include "person.h"
#include "decoration.h"

// Person
Person::Person(const std::string& name) : name(name) {}

std::string Person::getName() const {
    return name;
}

// Adult
Adult::Adult(const std::string& name, Price savings)
        : Person(name), savings(savings) {}

void Adult::update(ChristmasTree &christmasTree) const {
    std::cout << "We have new decoration!" << std::endl;
    std::cout << "Total cost is " << christmasTree.getPrice() << "." << std::endl;
}

void Adult::buyDecoration(Decoration& decoration) {
    savings -= decoration.getPrice();
}

Price Adult::getSavings() const {
    return savings;
}

//Child
Child::Child(const std::string& name) : Person(name) {}

void Child::update(ChristmasTree &christmasTree) const {
    std::cout << "Wow!" << std::endl;
    (*christmasTree.begin())->doOperation(std::cout);
}