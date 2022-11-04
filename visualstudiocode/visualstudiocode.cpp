#include <iostream>
#include "library.h"
#include "io.h"

int main()
{
    
    int a = getValueFromUser();
    int b = getValueFromUser();

    std::cout << a << " + "  << b << " = " << a + b << std::endl;

    std::cout << "Hello World!\n";

    std::cout << "the sum is - " << sum(&a, &b) << std::endl;

    std::cout << "the double number of first number is - " << doubleNumber(a) << std::endl;

    /*std::cout << "Enter your first number: " << std::endl;
    int uservalue1 = readNumber();
    std::cout << "Enter your second number: " << std::endl;
    int uservalue2 = readNumber();
    
    std::cout << "Here is your result: " << writeAnswer(uservalue1, uservalue2) << std::endl;*/

    return 0;
}
