#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <array>

int add(int x, int y) {
    return x + y;
}

int substract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

using arithmeticFcn = int(*)(int, int);

arithmeticFcn getArithmeticFcn(char op) {
    switch (op) {
    default:
    case '+':
        return add;
    case '-':
        return substract;
    case '*':
        return multiply;
    case '/':
        return divide;
    }
}

int mainlesson10_task1() {

    int x, y;
    char op;

    std::cout << "Enter first number: ";
    x = getIntFromUser();
    std::cout << "Enter second number: ";
    y = getIntFromUser();

    do {
        std::cout << "Enter math operator (+, -, *, /): ";
        op = getCharFromUser();
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    arithmeticFcn fcn = getArithmeticFcn(op);

    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << std::endl;

    return 0;
}