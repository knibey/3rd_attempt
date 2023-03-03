#include <array>
#include <iostream>
#include <string_view>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <vector>
#include <math.h>
#include <algorithm>

int getRandomNumbers(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::vector<int> getVector(int startnumber, int count, int random) {
    std::vector<int> numbers(static_cast<std::vector<int>::size_type>(count));

    int i{ startnumber };

    for (auto& number : numbers) {
        number = ((i*i) * random);
        i++;
    }

    return numbers;
}

std::vector<int> generateVector(int random) {
    std::cout << "Start where? ";
    int startnumber = getIntFromUser();

    std::cout << "How many? ";
    int count = getIntFromUser();

    return getVector(startnumber, count, random);
}

int getUserGuess() {
    int user_guess = getIntFromUser();

    return user_guess;
}

bool removeOrNot(std::vector<int>& numbers, int user_guess) {
    auto found(std::find(numbers.begin(), numbers.end(), user_guess));

    if (found == numbers.end()) {
        return false;
    }
    else {
        numbers.erase(found);
        return true;
    }
}

int closestOne(const std::vector<int>& numbers, int user_guess) {
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) {
        return (std::abs(user_guess - a) < (std::abs(user_guess - b))); });
}

void printTask(std::vector<int>::size_type count, int random) {
    std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by " << random << " ?" << std::endl;
}

void printWin(std::vector<int>::size_type left) {
    std::cout << "Nice" << std::endl;

    if (left == 0) {
        std::cout << "You won!" << std::endl;
    }
    else {
        std::cout << left << " number(s) left." << std::endl;
    }
}

void printLose(const std::vector<int>& numbers, int user_guess) {
    int closest{ closestOne(numbers, user_guess) };

    std::cout << user_guess << " is wrong." << std::endl;

    if (std::abs(closest - user_guess) <= 4) {
        std::cout << "Try " << closest << " next time." << std::endl;
    } else {
        std::cout << "LOH" << std::endl;
    }
}

bool playGame(std::vector<int>& numbers) {
    int user_guess{ getUserGuess() };

    if (removeOrNot(numbers, user_guess)) {
        printWin(numbers.size());

        return !numbers.empty();
    } else {
        printLose(numbers, user_guess);

        return false;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    rand();

    int random = getRandomNumbers(2, 4);
    std::vector<int> numbers{ generateVector(random) };

    printTask(numbers.size(), random);

    while(playGame(numbers));

    return 0;
}