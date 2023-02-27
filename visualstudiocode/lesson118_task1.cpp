#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <array>
#include <algorithm>

struct Student {
    std::string name{};
    int grade{};
};

int mainlesson118_task1() {
    std::array<Student, 8> arr{
      { {"Albert",3},
        {"Ben", 5},
        {"Christine", 2},
        {"Dan", 8},
        {"Enchilada", 4},
        {"Francis", 1},
        {"Greg", 3},
        {"Hagrid", 5} }
    };

    auto best{ std::max_element(arr.begin(),arr.end(), [](const auto& a, const auto& b) {return a.grade < b.grade; }) };

    std::cout << best->name << std::endl;

    return 0;
}