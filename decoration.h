#ifndef JNP1_ZADANIE5_DECORATION_H
#define JNP1_ZADANIE5_DECORATION_H

#include <string>
#include "helper.h"

// Component
class Decoration {
public:
    virtual std::string getName() = 0; // nie wiem, czy to też może być virtualne, jeśli christmas tree nie ma tego w specyfikacji :0
    virtual Price getPrice() = 0;
    virtual void doOperation() = 0;
};


// Composite
class ChristmasTree : public Decoration {
public:
    class iterator;

    void doOperation();
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

};

class Lights : public Decoration {

};

class Tree : public Decoration {

};

#endif //JNP1_ZADANIE5_DECORATION_H
