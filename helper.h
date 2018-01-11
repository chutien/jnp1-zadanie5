#ifndef JNP1_ZADANIE6_HELPER_H
#define JNP1_ZADANIE6_HELPER_H

#include <iostream>
#include <memory>
#include <list>

int randomNumber();

class Price {
private:
    int value;

public:
    explicit Price(int n = 0);

    Price operator+(const Price &) const;

    bool operator<(const Price &) const;

    const Price &operator-=(const Price &);

    // format: 1234 PLN
    friend std::ostream &operator<<(std::ostream &, const Price &);
};

class Date {
    int totalMinutes;

public:
    Date(int day, int hour, int minute);

    Date &operator++();

    int operator-(const Date &) const;

    bool operator<(const Date &) const;

    // format: December, 20, 13:04
    friend std::ostream &operator<<(std::ostream &, const Date &);
};

Date &currentDate();

class Observer;

class Observable {
    using obsElem = std::shared_ptr<Observer>;
    using obsList = std::list<obsElem>;
    using obsIterator = obsList::iterator;

private:
    obsList observers;

public:
    virtual obsIterator attachObserver(const std::shared_ptr<Observer> &);

    virtual void detachObserver(obsIterator);

    virtual void notify();

    virtual void doOperationOnLast(std::ostream &) = 0;

    virtual Price getPrice() const = 0;

    virtual ~Observable() {};
};

class Observer {
public:
    virtual void update(Observable &) const = 0;

    virtual ~Observer() {};
};

#endif //JNP1_ZADANIE6_HELPER_H
