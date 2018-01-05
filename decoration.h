#ifndef JNP1_ZADANIE5_DECORATION_H
#define JNP1_ZADANIE5_DECORATION_H

#include <string>
#include "helper.h"

// Component
class Decoration {
public:
    virtual std::string getName() = 0; // nie wiem, czy to też może być virtualne, jeśli christmas tree nie ma tego w specyfikacji :0
    virtual Price getPrice() = 0;
    virtual void doOperation(std::ostream &os) = 0;
};


// Composite
class ChristmasTree : public Decoration {
public:
    class iterator;

    void doOperation(std::ostream &os) override;
    Price getPrice();
    //void addDecoration(); // przez shared poiner??
    // void removeDecoration // przez iterator

    iterator begin();
    iterator end();
    void attachObserver(); // przez shared pointer
    void detachObserver(); // przez iterator?? how?
    void notify(); // informuje o zmianach stanu
};

// Leafs
class GlassBall : public Decoration {
private:
    bool isBroken = false;

public:
    void doOperation(std::ostream &os) override;
};

class Lights : public Decoration {
private:
    int currentState = 0;
    static std::string states[] = { "off", "constant", "blinking" };

public:
    void doOperation(std::ostream &os) override;
};

class Tree : public Decoration {

public:
    void doOperation(std::ostream &os) override;
};

#endif //JNP1_ZADANIE5_DECORATION_H
