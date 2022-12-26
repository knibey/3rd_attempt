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

int* getMyAge(int a) {
    return &a;
}

int* allocateArray(int size) {
    return new int[size];
}

int& getElement(std::array<int, 20>& array, int index) {
    return array[index];
}

int main106lesson() {
    int a = 21;

    std::array<int, 20> array1{ 0 };

    int* array = allocateArray(20);

    std::cout << *(getMyAge(a)) << std::endl;

    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    for (int i = 0; i < 20; i++) {
        std::cout << array[i] << std::endl;
    }

    std::cout << getElement(array1, 5) << std::endl;

    delete[] array;

    return 0;
}