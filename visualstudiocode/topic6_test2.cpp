#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>

struct Pupil {
    std::string name;
    int grade;
};

void arraySort(Pupil* pupils, int length) {
    for (int start_index = 0; start_index < length; ++start_index) {
        int largestIndex = start_index;

        for (int currentIndex = start_index; currentIndex < length; ++currentIndex) {
            if (pupils[currentIndex].grade > pupils[largestIndex].grade) {
                largestIndex = currentIndex;
            }
        }

        std::swap(pupils[start_index], pupils[largestIndex]);
    }
}

int maintopic6_test2() {

    std::cout << "How much pupils are in your class?" << std::endl;
    int class_size = getIntFromUser();

    Pupil* pupilclass = new Pupil[class_size];

    for (int i = 0; i < class_size; ++i) {
        std::cout << "Enter name for your pupil: ";
        pupilclass[i].name = getStringFromUser();
        std::cout << "Enter grade for your pupil: ";
        pupilclass[i].grade = getIntFromUser();
    }

    arraySort(pupilclass, class_size);

    for (int i = 0; i < class_size; ++i) {
        std::cout << pupilclass[i].name << " got a grade of " << pupilclass[i].grade << std::endl;
    }

    delete[] pupilclass;

    return 0;
}