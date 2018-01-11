#ifndef JNP1_ZADANIE6_DECORATION_H
#define JNP1_ZADANIE6_DECORATION_H

#include <string>
#include <list>
#include <memory>
#include "helper.h"

class Decoration {
protected:
    const std::string name;
    explicit Decoration(const std::string &);

public:
    std::string getName() const;
    virtual Price getPrice() const = 0;
    virtual void doOperation(std::ostream &os) = 0;
    virtual ~Decoration() {};
};

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

class DecorationWithPrice : public Decoration {
protected:
    const Price price;
    DecorationWithPrice(const std::string &, const Price &);
public:
    Price getPrice() const override;
};

class GlassBall : public DecorationWithPrice {
private:
    bool isBroken = false;

public:
    GlassBall() = delete;
    GlassBall(const std::string &, const Price &);

    void doOperation(std::ostream &os) override;
};

class Lights : public DecorationWithPrice {
private:
    int currentState = 0;

public:
    Lights() = delete;
    Lights(const std::string &, const Price &);

    void doOperation(std::ostream &os) override;
};

class Tree : public DecorationWithPrice {
private:
    const Date cutDate;

public:
    Tree() = delete;
    Tree(const std::string &, const Price &, const Date &);

    void doOperation(std::ostream &os) override;
};

#endif //JNP1_ZADANIE6_DECORATION_H
