#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <array>

struct Animal {};

int sumTo(const int max);

void printAnimalName(const Animal &animal);

int minMax(const int value1, const int value2, int& maxOut, int& minOut);

int getIndexOfLargestValue(const int *array, const int length);

const int& getElement(const int* array, const int index);

int main() {
    return 0;
}