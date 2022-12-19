#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>

void switchValues(int &firstvalue, int &secondvalue) {
    int temp = firstvalue;
    firstvalue = secondvalue;
    secondvalue = temp;
}

int maintopic6_test3() {
    int firstvalue = getIntFromUser();
    int secondvalue = getIntFromUser();

    std::cout << "here is your first number - " << firstvalue << " and second number - " << secondvalue << std::endl;
    switchValues(firstvalue, secondvalue);
    std::cout << "here is your first number - " << firstvalue << " and second number - " << secondvalue << std::endl;

    return 0;
}