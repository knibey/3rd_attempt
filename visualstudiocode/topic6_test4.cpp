#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>

void cstyleOut(const char *string) {
    for (int size = 0; string[size] != '\0'; size++) {
        std::cout << string[size];
    }
}

int maintopic6_test4() {

    cstyleOut("Hello, World");

    return 0;
}