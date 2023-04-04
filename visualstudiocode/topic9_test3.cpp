#include <iostream>

class IntArray {
private:
	int m_length = 0;
	int* m_array = nullptr;
public:
	IntArray(int length = 1) : m_length(length) {
		m_array = new int[m_length] {0};
	}

	IntArray(const IntArray& arr) :m_length(arr.m_length) {
		m_array = new int[m_length];

		for (int i = 0; i < m_length; ++i) {
			m_array[i] = arr.m_array[i];
		}
	}

	~IntArray() {
		delete[] m_array;
	}

	friend std::ostream& operator<< (std::ostream& out, const IntArray& arr) {
		for (int i = 0; i < arr.m_length; ++i) {
			out << arr.m_array[i] << " ";
		}

		return out;
	}

	int& operator[] (int index) {
		return m_array[index];
	}

	IntArray& operator= (const IntArray& arr) {
		if (this == &arr) {
			return *this;
		}
		
		delete[] m_array;

		m_length = arr.m_length;

		m_array = new int[m_length];

		for (int i = 0; i < m_length; ++i) {
			m_array[i] = arr.m_array[i];
		}

		return *this;
	}
};


IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 8;

	return a;
}

int maintopic9_test3()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}