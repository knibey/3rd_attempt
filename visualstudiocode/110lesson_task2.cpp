#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <array>

using arithmeticFcn = int(*)(int, int);

struct arithmeticStruct {
    char op;
    arithmeticFcn fcn;
};

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

static arithmeticStruct arithmeticArrray[]{
    {'+', add},
    {'-', substract},
    {'*', multiply},
    {'/', divide}
};

arithmeticFcn getArithmeticFcn(char op) {
    for (auto &element : arithmeticArrray) {
        if (element.op == op) {
            return element.fcn;
        }
    }
    return add;
}

int mainlesson110_task2() {

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