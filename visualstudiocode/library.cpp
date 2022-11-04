#include <iostream>

int doubleNumber(int a) {
    return a * 2;
}

int getValueFromUser() {
    int x;

    std::cin >> x;

    return x;
}

int sum(int* dodanok1, int* dodanok2) {
    return *dodanok1 + *dodanok2;
}
