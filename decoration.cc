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

void ChristmasTree::addDecoration(std::shared_ptr<Decoration> decoration) {
    decorations.push_front(std::move(decoration));
    notify();
}

void ChristmasTree::attachObserver(std::shared_ptr<Person> observer) {
    observers.push_back(std::move(observer));
}

void ChristmasTree::notify() {
    for (auto &observer : observers) {
        observer->update(*this);
    }
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
    int diff = cutDate - currentDate();
    double needlesPercentage = 2 / (1 + std::exp(diff / 8640));
    os << getName() << ": " << needlesPercentage << "% of tree covered with needles" << std::endl;
}