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
#include <math.h>

int getRandomNumbers(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::vector<int> getVector(int size, int randomnumber, int startnumber) {
    std::vector<int> numbers{ 0 };
    numbers.resize(size);

    for (int i = 0; i < size; i++) {
        numbers[i] = pow(startnumber, 2);
        startnumber++;
    }

    for (int i = 0; i < size; i++) {
        numbers[i] *= randomnumber;
    }

    return numbers;
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    rand();

    int randomnumber = getRandomNumbers(2, 4);
    std::cout << "random number is: " << randomnumber << std::endl;

    std::cout << "Start where? " << std::endl;
    int startnumber = getIntFromUser();

    std::cout << "How many" << std::endl;
    int count = getIntFromUser();

    std::vector<int> numbers = getVector(count, randomnumber, startnumber);

    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << " ";
    }

    std::cout << "\nI generated " << count << " square numbers. Do you know what each number is after multiplying it by " << randomnumber <<" ?" << std::endl;

    int user_guess{ 0 };

    while (numbers.size() != 0) {
        user_guess = getIntFromUser();

        auto found{ std::find(numbers.begin(), numbers.end(), user_guess) };

        if (found != std::end(numbers)) {
            std::cout << "Nice!" << std::endl;
        }

        numbers.erase(found);

    }

    return 0;
}