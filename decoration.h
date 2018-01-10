#ifndef JNP1_ZADANIE6_DECORATION_H
#define JNP1_ZADANIE6_DECORATION_H

#include <string>
#include <list>
#include <memory>
#include "helper.h"

// Component
class Decoration {
protected:
    const std::string name;
    explicit Decoration(const std::string &);

public:
    std::string getName() const;
    virtual Price getPrice() const = 0;
    virtual void doOperation(std::ostream &os) = 0;
};


// Composite, Observable
class ChristmasTree : public Decoration, public Observable {
protected:
    using decElem = std::shared_ptr<Decoration>;
    using decList = std::list<decElem>;

private:
    decList decorations;

public:
    using decIterator = decList::iterator;

    ChristmasTree() = delete;

    explicit ChristmasTree(const std::string &);

    Price getPrice() const override;
    void doOperation(std::ostream &) override;
    void doOperationOnLast(std::ostream &) override;
    void addDecoration(const std::shared_ptr<Decoration>&);
    void removeDecoration(decIterator); // przez iterator
    decIterator begin();
    decIterator end();
    
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
