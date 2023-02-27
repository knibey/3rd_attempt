#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <vector>

int getRandomNumbers(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::vector<int> generateNumbers(int start, int count, int multiplier) {
    std::vector<int> numbers(static_cast<std::vector<int>::size_type>(count));

    int i = start;

    for (auto& number : numbers) {
        number = ((i * i) * multiplier);
        i++;
    }

    return numbers;
}

bool eraseUserGuess(std::vector<int>& numbers, int user_guess) {
    if (auto found{ std::find(numbers.begin(), numbers.end(), user_guess) }; found == numbers.end()) {
        return false;
    }
    else {
        numbers.erase(found);
        return true;
    }
}

int findClosest(const std::vector<int>& numbers, int guess) {
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) {
        return (std::abs(a - guess) < std::abs(b - guess));
        });
}

int mainlesson119_task3() {
    srand(static_cast<unsigned int>(time(0)));
    rand();

    std::cout << "Start where? ";
    int start_where = getIntFromUser();
    std::cout << "How many? ";
    int how_many = getIntFromUser();

    int randnumber = getRandomNumbers(2, 4);

    std::vector<int> numbers = generateNumbers(start_where, how_many, randnumber);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    int user_guess = getIntFromUser();

    return 0;
}