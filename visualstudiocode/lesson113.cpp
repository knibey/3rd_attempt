#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <array>

int factorial(int number) {
    if (number < 1) {
        return 1;
    }
    return factorial(number - 1) * number;
}

int sum(int number) {
    if (number == 0) {
        return 0;
    }
    return sum(number / 10) + number % 10;
}

void binarReverse(unsigned int number) {
    if (number == 0) {
        return;
    }
    
    binarReverse(number / 2);

    std::cout << number % 2;
}

int main() {

    int number = getIntFromUser();

    if (number < 0) {
        static_cast<unsigned int>(number);
    }

    binarReverse(number);

    return 0;
}