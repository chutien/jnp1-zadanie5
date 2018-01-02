#ifndef JNP1_ZADANIE5_PERSON_H
#define JNP1_ZADANIE5_PERSON_H

#include <string>
#include "helper.h"
#include "decoration.h"

class Person {
public:
    std::string getName();
};

class Adult : public Person {
    Price savings;

public:
    Adult(std::string& name, Price savings);

    void buyDecoration(Decoration decoration);
    Price getSavings();
};

class Child : public Person {
public:
    Child(std::string& name) {}
};


#endif //JNP1_ZADANIE5_PERSON_H
