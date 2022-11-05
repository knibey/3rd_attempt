#include <iostream>
#include "library.h"
#include "constants.h"

int main() {

    std::cout << "Enter the initial height of the tower in meters: ";
    double height = getDoubleFromUser();
    
    for (int i = 0; i <= height; i++) {
        double ball_height = constants::my_gravity * (i * i) / 2;

        if (height - ball_height <= 0) {
            std::cout << "At " << i << " seconds, the ball is on the ground" << std::endl;
            break;
        }

        std::cout << "At " << i << " seconds, the ball is at height: " << height - ball_height << " meters" << std::endl;
    }




    /*std::cout << "Enter a double value: ";
    double value1 = getDoubleFromUser();

    std::cout << "Enter a double value: ";
    double value2 = getDoubleFromUser();
    
    std::cout << "Enter one of the following: +, -, *, /: ";
    char op = getCharFromUser();

    switch (op) {
    case '+':
        std::cout << value1 << " + " << value2 << " = " << value1 + value2;
        break;
    case '-':
        std::cout << value1 << " - " << value2 << " = " << value1 - value2;
        break;
    case '*':
        std::cout << value1 << " * " << value2 << " = " << value1 * value2;
        break;
    case '/':
        std::cout << value1 << " / " << value2 << " = " << value1 / value2;
        break;
    }
    
    char ch{97};
    std::cout << "ITS A LITERA - " << ch << std::endl;
    std::cout << "ITS A NUMBER - " << static_cast<int>(ch) << std::endl;
    
    std::cout << constants::pi << std::endl;
    
    int value = getValueFromUser();

    bool prime = isPrime(value);
    
    if (prime) {
        std::cout << "its prime" << std::endl;
    } else {
        std::cout << "its not prime" << std::endl;
    }
        
    int a = getValueFromUser();
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
