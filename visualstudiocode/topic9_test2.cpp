#include <iostream>

class Average {
private:
	int32_t m_sum;
	int8_t m_count;
public:
	Average(int32_t sum = 0, int8_t count = 0) : m_sum(sum), m_count(count) {}
	
	Average& operator+= (int value) {
		++m_count;
		m_sum += value;
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, const Average& av);
};

std::ostream& operator<< (std::ostream& out, const Average& av) {
	out << static_cast<double>(av.m_sum) / av.m_count;
	return out;
}

int maintopic9_test2()
{
	Average avg;

	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5

	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7

	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

	(avg += 7) += 11; // виконання "ланцюжка" операцій
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}