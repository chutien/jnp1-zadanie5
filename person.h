#ifndef JNP1_ZADANIE6_PERSON_H
#define JNP1_ZADANIE6_PERSON_H

#include <memory>
#include <string>
#include "helper.h"

class Decoration;
class ChristmasTree;

class Person {
protected:
    const std::string name;

    explicit Person(std::string);

public:
    Person() = delete;
    std::string getName() const;
    virtual void update(ChristmasTree &) const = 0;
};

class Adult : public Person {
private:
    Price savings;

public:
    //Adult(std::string);
    Adult(std::string name, Price savings = Price());

    void buyDecoration(Decoration& decoration);
    Price getSavings() const;
    void update(ChristmasTree &) const override;
};

class Child : public Person {
public:
    explicit Child(std::string name);

    void update(ChristmasTree &) const override;
};


#endif //JNP1_ZADANIE6_PERSON_H
