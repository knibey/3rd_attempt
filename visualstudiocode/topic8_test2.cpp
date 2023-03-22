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

class Welcome
{
private:
	char* m_data;

public:
	Welcome()
	{
		m_data = new char[14];
		const char* init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~Welcome() {

		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data;
	}


};

int maintopic8_test2()
{
	Welcome hello;
	hello.print();

	return 0;
}