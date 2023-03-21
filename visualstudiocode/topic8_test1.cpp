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

class Point {
private:
	double m_a{ 0 };
	double m_b{ 0 };

public:
	Point() {}

	Point(double a, double b) : m_a(a), m_b(b) {}

	void print() const {
		std::cout << "Point (" << m_a << ", " << m_b << ")" << std::endl;
	}

	friend double distanceTo(const Point& a, const Point& b);
};

double distanceTo(const Point& a, const Point& b) {
	return sqrt((a.m_a - b.m_a) * (a.m_a - b.m_a) + (a.m_b - b.m_b) * (a.m_b - b.m_b));
}

int main()
{
	Point first;
	Point second(2.0, 5.0);
	first.print();
	second.print();

	return 0;
}