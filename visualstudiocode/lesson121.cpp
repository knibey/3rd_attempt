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

class Numbers {
public:
    int m_first;
    int m_second;


    void set(int first_value, int second_value) {
        m_first = first_value;
        m_second = second_value;
    }

    void print() {
        std::cout << "here are your numbers: " << m_first << " and " << m_second << std::endl;
    }

};

int mainlesson121()
{
    Numbers n1;
    n1.set(3, 3);

    Numbers n2{ 4, 4 };

    n1.print();
    n2.print();

    return 0;
}