#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

int main11() {
    std::string names[8] = {"Sasha","Ivan","John","Orlando","Leonardo","Nina","Anton","Molly"};

    std::string user_name = getStringFromUser();
    bool found = false;

    for (auto &comparison : names) {
        if (comparison == user_name) {
            found = true;
        }
    }

    if (found) {
        std::cout << user_name << " is found." << std::endl;
    }
    else {
        std::cout << user_name << " is not found." << std::endl;
    }

    return 0;
}