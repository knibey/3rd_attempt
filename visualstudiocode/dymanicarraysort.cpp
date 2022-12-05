#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

int main445() {

    std::cout << "How many names u wanna type in?: ";
    int length = getIntFromUser();

    std::string *names = new std::string[length];

    for (int i = 0; i < length; ++i) {
        std::cout << "Enter name #" << i+1 << ": ";
        names[i] = getStringFromUser();
    }

    stringSort(names, length);

    std::cout << "------------------------------------" << std::endl;
    std::cout << "Below is sorted array of std::string" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for ( int i = 0; i < length; ++i ) {
        std::cout << "#" << i + 1 << " name is - " << names[i] << std::endl;
    }

    delete[] names;
    names = nullptr;

    return 0;
}