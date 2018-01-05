#include "decoration.h"

void GlassBall::doOperation(std::ostream &os) {
    if (!isBroken && randomNumber()%4 == 0)
        isBroken |= true;
    os << (isBroken ? "broken" : "OK") << std::endl;
}

void Lights::doOperation(std::ostream &os) {
    currentState++;
    currentState%=3;
    os << states[currentState] << std::endl;
}

void Tree::doOperation(std::ostream &os) {

}
