#ifndef JNP1_ZADANIE6_DECORATION_H
#define JNP1_ZADANIE6_DECORATION_H

#include <string>
#include <list>
#include <memory>
#include "helper.h"

class Person;

// Component
class Decoration {
protected:
    const std::string name;
    explicit Decoration(const std::string &);

public:
    // Julia: nie wiem, czy to też może być virtualne, jeśli christmas tree nie ma tego w specyfikacji :0
    // Tien: skoro i tak chcemy miec pure metody do chyba nie ma sensu trzymac getName w abstract klasie, gdy i tak w leafs trzeba ja przepisac.
    // Tien: zauwazylem, ze w tresci konstruktor christmasTree wywolany jest z parametrem string
    std::string getName() const;
    virtual Price getPrice() const = 0;
    virtual void doOperation(std::ostream &os) = 0;
};


// Composite, Observable
class ChristmasTree : public Decoration {
protected:
    using decElem = std::shared_ptr<Decoration>;
    using decList = std::list<decElem>;

private:
    decList decorations;
    std::list<std::shared_ptr<Person>> observers;

public:
    using decIterator = decList::iterator;

    class obsIterator;

    ChristmasTree() = delete;
    ChristmasTree(const std::string &);

    Price getPrice() const override;
    void doOperation(std::ostream &os) override;
    //void addDecoration(); // przez shared poiner??
    void addDecoration(std::shared_ptr<Decoration>); //value czy &
    void removeDecoration(decIterator); // przez iterator
    decIterator begin();
    decIterator end();
    void attachObserver(std::shared_ptr<Person>); // przez shared pointer
    void detachObserver(obsIterator); // J: przez iterator?? how? T: xd
    void notify(); // informuje o zmianach stanu
};

// Leafs
class GlassBall : public Decoration {
private:
    const Price price;
    bool isBroken = false;

public:
    GlassBall() = delete;
    GlassBall(const std::string &, const Price &);

    Price getPrice() const override;
    void doOperation(std::ostream &os) override;
};

class Lights : public Decoration {
private:
    const Price price;
    int currentState = 0;
    static std::string states[3];

public:
    Lights() = delete;
    Lights(const std::string &, const Price &);

    Price getPrice() const override;
    void doOperation(std::ostream &os) override;
};

class Tree : public Decoration {
private:
    const Price price;
    const Date cutDate;

public:
    Tree() = delete;
    Tree(const std::string &, const Price &, const Date &);

    Price getPrice() const override;
    void doOperation(std::ostream &os) override;
};

#endif //JNP1_ZADANIE6_DECORATION_H
