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

int binarySearch(int* array, int target, int min, int max) {
    while (min <= max) {
        int mid = (max + min) / 2;
        
        if (array[mid] > target) {
            max = mid - 1;
        }
        
        if (array[mid] < target) {
            min = mid + 1;
        }
        
        if (array[mid] == target) {
            return mid;
        }
    }

    return -1;

}

int binarySearchrec(int* array, int target, int min, int max) {
    if (min > max) {
        return -1;
    }
    
    int mid = (max + min) / 2;

    if (array[mid] > target) {
        return binarySearchrec(array, target, min, mid - 1);
    } else if (array[mid] < target) {
        return binarySearchrec(array, target, mid + 1, max);
    } else {
        return mid;
    }
}

int main()
{
    int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

    std::cout << "Enter a number: ";
    int x = getIntFromUser();

    int index = binarySearchrec(array, x, 0, 14);

    if (array[index] == x)
        std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
    else
        std::cout << "Fail! Your value " << x << " isn't in array!\n";
    return 0;
}