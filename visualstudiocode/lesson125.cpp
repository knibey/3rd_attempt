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
#include <cstdint>

class RGBA {
private:
    std::uint8_t m_red{ 0 };
    std::uint8_t m_green{ 0 };
    std::uint8_t m_blue{0};
    std::uint8_t m_alpha{ 255 };
public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) 
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) 
    {
    }
    void print() {
        std::cout << "r=" << static_cast<int>(m_red) << 
            " g=" << static_cast<int>(m_green) << 
            " b=" << static_cast<int>(m_blue) << 
            " a=" << static_cast<int>(m_alpha) << 
            std::endl;
    }
};


int mainlesson125()
{
    RGBA color(0, 135, 135);
    color.print();

    return 0;
}