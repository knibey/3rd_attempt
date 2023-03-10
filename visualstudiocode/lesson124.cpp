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

class Ball {
private:
    std::string m_color;
    double m_radius;

public:
    Ball(double radius) {
        m_color = "red";
        m_radius = radius;
    }
    
    Ball(const std::string &color="Red", double radius=20.0) {
        m_color = color;
        m_radius = radius;
    };

    void print() {
        std::cout << "color: " << m_color << ", radius:" << m_radius << std::endl;
    }
};