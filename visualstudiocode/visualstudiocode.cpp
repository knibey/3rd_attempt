#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>

/*enum class MonsterType {
    OGRE,
    GOLBIN,
    SKELETON,
    ORC,
    TROLL
};

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
*/

/*struct Monster {
    MonsterType type;
    std::string name;
    int hp;
};

std::string getMonsterType(Monster monster) {
    switch (monster.type)
    {
    case MonsterType::OGRE:
        return "Ogre";
    case MonsterType::GOLBIN:
        return "Goblin";
    case MonsterType::SKELETON:
        return "Skeleton";
    case MonsterType::ORC:
        return "Orc";
    case MonsterType::TROLL:
        return "Troll";
    default:
        return "Unknown";
    }
}

void printMonster(Monster monster) {
    std::cout << "This " << getMonsterType(monster) << " is named " << monster.name << " and has " << monster.hp << " health." << std::endl;
}*/

/*int calcute(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
        default:
            return 0;
    }
}*/

enum class Animal {
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH
};

std::string getAnimalName(Animal animal) {
    switch (animal) {
        case Animal::PIG:
            return "Pig";
        case Animal::CHICKEN:
            return "Chicken";
        case Animal::GOAT:
            return "Goat";
        case Animal::CAT:
            return "Cat";
        case Animal::DOG:
            return "Dog";
        case Animal::OSTRICH:
            return "Ostrich";
        default:
            return "ERROR_UNKNOWN_ANIMAL";
    }
}

int printNumberOfLegs(Animal animal) {
    switch (animal) {
    case Animal::PIG:
        return 4;
    case Animal::CHICKEN:
        return 2;
    case Animal::GOAT:
        return 4;
    case Animal::CAT:
        return 4;
    case Animal::DOG:
        return 4;
    case Animal::OSTRICH:
        return 2;
    default:
        return 0;
    }
}

int sumTo(int value) {
    int result = 0;
    for (int i = 0; i <= value; i++) {
        result += i;
    }
    return result;
}

/*int main() {

    std::cout << "This is sumTo() function - " << sumTo(5) << std::endl;
    

    std::cout << "This is FOR loop: " << std::endl;
    for (int i = 0; i <= 20; i += 2) {
        std::cout << i << std::endl;
    }
    
    /*int outer = 1;
    while (outer <= 5) {

        int inner = 5;
        while (inner >= 1) {
            if (inner <= outer) {
                std::cout << inner << " ";
            } else {
                std::cout << "  ";
            }

            --inner;
        }

        std::cout << "\n";
        ++outer;
    }
    
    /*char alphabet = 'a';

    while (alphabet <= 'z') {
        std::cout << alphabet << " - " << static_cast<int>(alphabet) << std::endl;

        ++alphabet;
    }

    /*Animal cat = Animal::CAT;
    Animal chicken = Animal::CHICKEN;

    std::cout << "A " << getAnimalName(cat) << " has " << printNumberOfLegs(cat) << " legs" << std::endl;
    std::cout << "A " << getAnimalName(chicken) << " has " << printNumberOfLegs(chicken) << " legs" << std::endl;

    /*std::cout << "Enter first number: ";
    int a = getIntFromUser();

    std::cout << "Enter second number: ";
    int b = getIntFromUser();

    std::cout << "Enter operator: ";
    char op = getCharFromUser();

    for (; ;) {
        if ((op != '-') && (op != '+') && (op != '*') && (op != '/') && (op != '%')) {
            std::cout << "ERROR_BAD_OPERATOR" << std::endl;
            std::cout << "Enter valid operator: ";
            op = getCharFromUser();
        } else {
            break;
        }
    }

    std::cout << "Your result is: " << a << ' ' << op << ' ' << b << " = " << calcute(a, b, op) << std::endl;
    
    
    /*Monster john = {MonsterType::GOLBIN, "John", 170};
    Monster james = { MonsterType::ORC, "James", 35 };

    printMonster(john);
    printMonster(james);
    
    
    
    /*Drobi firstd;
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
    
    std::cout << "Here is your result: " << writeAnswer(uservalue1, uservalue2) << std::endl;

    return 0;
}
*/