#ifndef JNP1_ZADANIE6_PERSON_H
#define JNP1_ZADANIE6_PERSON_H

#include <memory>
#include <string>
#include "helper.h"
#include "decoration.h"


class Person : public Observer {
protected:
    const std::string name;

    explicit Person(const std::string &);

public:
    Person() = delete;

    std::string getName() const;
};

class Adult : public Person {
private:
    Price savings;

public:
    explicit Adult(const std::string &name, Price savings = Price());

    void buyDecoration(const Decoration &);

    Price getSavings() const;

    void update(Observable &) const override;
};

class Child : public Person {
public:
    explicit Child(const std::string &name);

    void update(Observable &) const override;
};


#endif //JNP1_ZADANIE6_PERSON_H
