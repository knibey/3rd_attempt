#include <iostream>
#include "library.h"


int main()
{
    
    int a = getValueFromUser();
    int b = getValueFromUser();

    std::cout << a << " + "  << b << " = " << a + b << std::endl;

    std::cout << "Hello World!\n";

    std::cout << "the sum is - " << sum(&a, &b) << std::endl;

    std::cout << "the double number of first number is - " << doubleNumber(a) << std::endl;

    return 0;
}
