#ifndef JNP1_ZADANIE6_PERSON_H
#define JNP1_ZADANIE6_PERSON_H

#include <bits/shared_ptr.h>
#include <string>
#include "helper.h"
#include "decoration.h"

class Person {
protected:
    Person() = default;
    std::string name;

public:
    std::string getName() const;
    virtual void update() = 0;
};

class Adult : public Person {
private:
    Price savings;

public:
    Adult(std::string& name, Price savings);

    void buyDecoration(const std::shared_ptr<Decoration> &decoration);
    Price getSavings() const;
};

class Child : public Person {
public:
    explicit Child(std::string& name) {}
};


#endif //JNP1_ZADANIE6_PERSON_H
