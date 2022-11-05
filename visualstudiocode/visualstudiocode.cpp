#include <iostream>
#include "library.h"

int main()
{
    int value = getValueFromUser();

    bool prime = isPrime(value);
    
    if (prime) {
        std::cout << "its prime" << std::endl;
    } else {
        std::cout << "its not prime" << std::endl;
    }
    
    
    /*int a = getValueFromUser();
    int b = getValueFromUser();

    int ahsala{5036};

    std::cout << a << " + "  << b << " = " << a + b << std::endl;

    std::cout << "Hello World!\n";

    std::cout << "the sum is - " << sum(&a, &b) << std::endl;

    std::cout << "the double number of first number is - " << doubleNumber(a) << std::endl;

    std::cout << ahsala << std::endl;

    std::cout << "Enter your first number: " << std::endl;
    int uservalue1 = readNumber();
    std::cout << "Enter your second number: " << std::endl;
    int uservalue2 = readNumber();
    
    std::cout << "Here is your result: " << writeAnswer(uservalue1, uservalue2) << std::endl;*/

    return 0;
}
