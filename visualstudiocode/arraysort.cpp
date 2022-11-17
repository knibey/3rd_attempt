#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    const int length = 9;
    int array[length] = {7,5,6,4,9,8,2,1,3};

    for (int iteration = 0; iteration < length - 1; ++iteration) {
        for (int currentIndex = 0; currentIndex < length - 1; ++currentIndex) {
            if (array[currentIndex] < array[currentIndex+1]) {
                std::swap(array[currentIndex], array[currentIndex+1]);
            }
        }
    }

    for (int i = 0; i < length; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}