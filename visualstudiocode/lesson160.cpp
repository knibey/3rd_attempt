#include <iostream> 
#include <cassert> // ��� assert()
#include <initializer_list> // ��� std::initializer_list

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() :
		m_length(0), m_data(nullptr)
	{
	}

	ArrayInt(int length) :
		m_length(length)
	{
		m_data = new int[length];
	}

	ArrayInt(const std::initializer_list<int>& list) : // ���������� ����������� ArrayInt ����� ������ �����������
		ArrayInt(list.size()) // ������������� ��������� ����������� ������������ ��� ��������� ����������� ������, � ���� ������ ���������� ��������
	{
		// ����������� ������ ����������� ������ ���������� � ������ �����������
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	ArrayInt& operator=(const std::initializer_list<int>& list) {
		
		if (list.size() != static_cast<size_t>(m_length))
		{
			// ��������� �� ������� ��������
			delete[] m_data;

			// ������������ �����
			m_length = list.size();
			m_data = new int[m_length];
		}

		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}

		return *this;
	}

	~ArrayInt()
	{
		delete[] m_data;
		// ��� �� ������� ��� ����������� �������� null ��� m_data �� ���������� m_length = 0, ���� �� ��'��� ��������� ������ ���� ��������� ���� �������
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() { return m_length; }


};

int main()
{
	ArrayInt array{ 7, 6, 5, 4, 3, 2, 1 }; // ������ �����������
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 4, 9, 12, 15, 17, 19, 21 };

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	return 0;
}