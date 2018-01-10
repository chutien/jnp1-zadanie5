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

    Price operator+(const Price& other) const;
    bool operator<(const Price& other) const;
    const Price& operator-=(const Price& other);

    // format: 1234 PLN
    friend std::ostream& operator<<(std::ostream& os, const Price& price);
};

class Date {
    int totalMinutes;

public:
    Date(int day, int hour, int minute);

    // + 1 minuta
    Date& operator++();
    int operator-(const Date& other) const;
    bool operator<(const Date& other) const;

    // format: December, 20, 13:04
    friend std::ostream& operator<<(std::ostream& os, const Date& Date);
};

Date& currentDate();

class Observer;

class Observable {
    using obsElem = std::shared_ptr<Observer>;
    using obsList = std::list<obsElem>;
    using obsIterator = obsList::iterator;

private:
    obsList observers;

public:
    virtual obsIterator attachObserver(const std::shared_ptr<Observer> &);
    virtual void detachObserver(obsIterator) ; // J: przez iterator?? how? T: xd
    virtual void notify();
    virtual void doOperationOnLast(std::ostream &os) = 0;
    virtual Price getPrice() const = 0;
};

class Observer {
public:
    virtual void update(Observable &) const = 0;
};

#endif //JNP1_ZADANIE6_HELPER_H
