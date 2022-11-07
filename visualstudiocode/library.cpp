#include <iostream>

int doubleNumber(int a) {
    return a * 2;
}

int getIntFromUser() {
    int x;

    std::cin >> x;

    return x;
}

double getDoubleFromUser() {
    double x;

    std::cin >> x;

    return x;
}

char getCharFromUser() {
    char x;

    std::cin >> x;

    return x;
}

int sum(int* dodanok1, int* dodanok2) {
    return *dodanok1 + *dodanok2;
}

bool isPrime(int x) {
    if (x == 2) {
        return 1;
    }

    if (x < 2) {
        return 0;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }

    return 1;
}

bool isEven(int value) {
    return value % 2 == 0;
}