#include <iostream>
#include <memory>
#include "helper.h"
#include "decoration.h"
#include "person.h"

using namespace std;

int main() {
    Date d(10, 10, 10);
    Date d2(31, 23, 59);
    Date d3(0, 0, 0);
    cout << d << d2 << d3;
}