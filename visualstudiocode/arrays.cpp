#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

namespace Animals {
    enum Animals {
        CHICKEN,
        LION,
        GIRAFFE,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS
    };
}

int main1() {
    double temp[365] = {0.0};

    int numbalegs[Animals::MAX_ANIMALS] = {2,4,4,4,2,0};

    std::cout << numbalegs[Animals::ELEPHANT] << std::endl;

    std::cout << "----------------------------------------" << std::endl;

    int array[] = {7,5,6,4,9,8,2,1,3};

    int array_size = sizeof(array) / sizeof(array[0]);

    int userinput = 0;
    while (true) {
        userinput = 5;
        if (userinput < array_size && userinput > 1) {
            break;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
    }


    for (int i = 0; i < array_size; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << array[userinput] << std::endl;

    std::cout << "----------------------------------------" << std::endl;



    return 0;
}