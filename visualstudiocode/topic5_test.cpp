#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool playGame(int attempts, int random) {

    for (int attemptcounter = 1; attemptcounter <= attempts; ++attemptcounter) {

        std::cout << "Guess #" << attemptcounter << ": ";
        int user_guess = getIntFromUser();

        if (user_guess < random) {
            std::cout << "Your guess is too low." << std::endl;
        } else if (user_guess > random) {
            std::cout << "Your guess is too high." << std::endl;
        } else {
            return true;
        }
    }

    return false;
}

bool playAgain() {
    char answer;

    do {
        std::cout << "Do you wanna play again? (y/n): ";
        answer = getCharFromUser();
    } while (answer != 'y' && answer != 'n');

    return (answer == 'y');
}

int main_topic5() {
    srand(static_cast<unsigned int>(time(0)));
    rand();

    const int attempts = 7;
    
    do {

        int random = getRandomNumber(1, 100);

        bool won = playGame(attempts, random);

        if (won) {
            std::cout << "Youre correct! You won!" << std::endl;
        } else {
            std::cout << "You lose. Correct number is: " << random << std::endl;
        }

    } while (playAgain());

    std::cout << "Thanks for playing." << std::endl;

    return 0;
}