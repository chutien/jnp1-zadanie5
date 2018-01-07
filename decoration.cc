#include "decoration.h"
#include <cmath>

// Decoration
Decoration::Decoration(const std::string &name) : name(name) {}

std::string Decoration::getName() const {
    return name;
}

// ChristmasTree
ChristmasTree::ChristmasTree(const std::string &name) : Decoration(name){}

void ChristmasTree::notify() {
    for (auto &observer : observers) {
        observer->update();
    }
}

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
    decorations.push_back(std::move(decoration));
}

void ChristmasTree::attachObserver(std::shared_ptr<Person> observer) {
    observers.push_back(std::move(observer));
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
    os << (isBroken ? "broken" : "OK") << std::endl;
}

// Lights
Lights::Lights(const std::string &name, const Price &price) :
        Decoration(name), price(price) {}

Price Lights::getPrice() const {
    return price;
}

void Lights::doOperation(std::ostream &os) {
    currentState++;
    currentState%=3;
    os << states[currentState] << std::endl;
}

// Tree
Tree::Tree(const std::string &name, const Price &price, const Date &cutDate) :
        Decoration(name), price(price), cutDate(cutDate) {}

Price Tree::getPrice() const {
    return price;
}

void Tree::doOperation(std::ostream &os) {
    int diff = cutDate - currentDate();
    double needlesPercentage = 1 / (1 + std::exp(diff / 800 - 8));
    os << needlesPercentage << std::endl;
}