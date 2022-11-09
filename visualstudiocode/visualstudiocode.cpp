#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>

struct Advertising {
    int ads;
    double percent;
    double income;
};

struct Drobi {
    int chiselnik;
    int znamennik;
};

float multiply(Drobi firstd, Drobi secondd) {
    return ((firstd.chiselnik * secondd.chiselnik) / (firstd.znamennik*secondd.znamennik));
}

int main() {

    Drobi firstd;
    Drobi secondd;

    firstd.chiselnik = getIntFromUser();
    firstd.znamennik = getIntFromUser();

    secondd.chiselnik = getIntFromUser();
    secondd.znamennik = getIntFromUser();

    std::cout << multiply(firstd, secondd);




    /*Advertising alltimeincome;

    alltimeincome.ads = getIntFromUser();
    alltimeincome.percent = getDoubleFromUser();
    alltimeincome.income = getDoubleFromUser();

    //std::cout << alltimeincome.ads << std::endl;
    //std::cout << alltimeincome.percent << std::endl;
    //std::cout << alltimeincome.income << std::endl;

    std::cout << alltimeincome.ads * (alltimeincome.percent / 100) * alltimeincome.income;

    /*enum Race {
        RACE_OGRE,
        RACE_GOBLIN,
        RACE_SKELETON,
        RACE_ORC,
        RACE_TROLL
    };
    
    Race monstertype = RACE_OGRE;

    //typedef int status_t;
    using status_t = int;
    status_t editData();

    /*std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    int age = getIntFromUser();

    double lived = (static_cast<double>(age)) / name.length();

    std::cout << "You've lived " << lived << " years for each letter in your name" << std::endl;





    /*std::cout << "Enter number: ";
    int a = getIntFromUser();

    std::cout << "Enter bigger number: ";
    int b = getIntFromUser();

    if (a > b) {
        std::cout << "Switching numbers" << std::endl;
        int temp;

        temp = b;
        b = a;
        a = temp;
    }

    std::cout << "Min number: " << a << std::endl;
    std::cout << "Max number: " << b << std::endl;
    
    
    /*std::cout << "Enter your number between 0 and 255: ";
    int x = getIntFromUser();

    x = convert(x, 128);
    x = convert(x, 64);
    x = convert(x, 32);
    x = convert(x, 16);

    std::cout << " ";

    x = convert(x, 8);
    x = convert(x, 4);
    x = convert(x, 2);
    x = convert(x, 1);
    
    
    /*int a = getIntFromUser();
    std::cout << std::boolalpha;
    std::cout << isEven(a);
    int x = 101;
    if ( x > 100 ) {
        std::cout << "bilshe" << std::endl;
    } else {
        std::cout << "menshe" << std::endl;
    }
    
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

    std::cout << "Enter a double value: ";
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
