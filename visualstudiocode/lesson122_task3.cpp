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
#include <cassert>

class Stack {
private:
    int array[10];
    int length;

public:

    void reset() {
        length = 0;
        for (int i = 0; i < 10; ++i)
            array[i] = 0;
    }

    bool push(int value) {
        if (length == 10) {
            return false;
        }

        array[length++] = value;
        return true;
    }

    int pop() {
        assert(length < 0);

        return array[--length];
    }

    void print() {
        std::cout << "( ";
        for (int i = 0; i < length; ++i)
            std::cout << array[i] << ' ';
        std::cout << ")\n";
    }

};

int mainlesson122_task3()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}