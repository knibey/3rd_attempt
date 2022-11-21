#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

int main25() {
    int a = 5;

    int *ptr1 = new int{ 95 };

    int *ptr = &a;

    std::cout << "this is just variable - " << a << std::endl;
    std::cout << "this is just pointer - " << ptr << std::endl;
    std::cout << "this is unnamed pointer - " << *ptr << std::endl;

    std::cout << "----------------------------------" << std::endl;

    std::cout << "this is just pointer from heap - " << ptr1 << std::endl;
    std::cout << "this is unnamed pointer from heap - " << *ptr1 << std::endl;

    std::cout << "----------------------------------" << std::endl;

    delete ptr1;
    ptr1 = nullptr;

    std::cout << "this is just deleted pointer - " << ptr1 << std::endl;

    return 0;
}