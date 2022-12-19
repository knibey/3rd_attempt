#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

enum ItemTypes {
    ITEM_HEALTH_POTION,
    ITEM_TORCH,
    ITEM_ARROW,
    MAX_ITEMS
};

int countTotalItems(int array[]) {
    int result = 0;

    for (int i = 0; i < MAX_ITEMS; ++i) {
        result += array[i];
    }

    return result;
}

int maintopic6test1() {

    int inventory[MAX_ITEMS]{3,6,12};

    std::cout << countTotalItems(inventory);

    return 0;
}