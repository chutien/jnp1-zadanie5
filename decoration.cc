#include "decoration.h"
#include "person.h"
#include "helper.h"
#include <cmath>

// Decoration
Decoration::Decoration(const std::string &name) : name(name) {}

std::string Decoration::getName() const {
    return name;
}

// ChristmasTree
ChristmasTree::ChristmasTree(const std::string &name) : Decoration(name){}

Price ChristmasTree::getPrice() const {
    Price sum(0);
    for (auto &decoration : decorations) {
        sum = sum + decoration->getPrice();
    }
    return sum;
}

void ChristmasTree::doOperation(std::ostream &os) {
    for (auto &decoration : decorations) {
        decoration->doOperation(os);
    }
}

void ChristmasTree::addDecoration(const std::shared_ptr<Decoration>& decoration) {
    decorations.push_front(decoration);
    notify();
}

void ChristmasTree::attachObserver(const std::shared_ptr<Person>& observer) {
    observers.push_back(observer);
}

void ChristmasTree::notify() {
    for (auto &observer : observers) {
        observer->update(*this);
    }
}

ChristmasTree::decIterator ChristmasTree::begin() {
    return decorations.begin();
}

ChristmasTree::decIterator ChristmasTree::end() {
    return decorations.end();
}

// GlassBall
GlassBall::GlassBall(const std::string &name, const Price &price) :
        Decoration(name), price(price) {}

Price GlassBall::getPrice() const {
    return price;
}

void GlassBall::doOperation(std::ostream &os) {
    if (!isBroken && randomNumber()%4 == 0)
        isBroken |= true;
    os << getName() << ": " << (isBroken ? "broken" : "OK") << std::endl;
}

// Lights
Lights::Lights(const std::string &name, const Price &price) :
        Decoration(name), price(price) {}

std::string Lights::states[] = { "off", "constant", "blinking" };

Price Lights::getPrice() const {
    return price;
}

void Lights::doOperation(std::ostream &os) {
    currentState++;
    currentState%=3;
    os << getName() << ": " << states[currentState] << std::endl;
}

// Tree
Tree::Tree(const std::string &name, const Price &price, const Date &cutDate) :
        Decoration(name), price(price), cutDate(cutDate) {}

Price Tree::getPrice() const {
    return price;
}

void Tree::doOperation(std::ostream &os) {
    int diff = currentDate() - cutDate;
    double needlesPercentage = 100.0 * 2 / (1.0 + std::exp(diff / 8640.0));
    os << getName() << ": " << needlesPercentage << "% of tree covered with needles" << std::endl;
}