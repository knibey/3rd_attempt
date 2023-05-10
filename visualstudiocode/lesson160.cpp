#include <iostream> 
#include <cassert> // для assert()
#include <initializer_list> // для std::initializer_list

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

	ArrayInt(const std::initializer_list<int>& list) : // дозволяємо ініціалізацію ArrayInt через список ініціалізації
		ArrayInt(list.size()) // використовуємо концепцію делегування конструкторів для створення початкового масиву, в який будуть копіюватися елементи
	{
		// Ініціалізація нашого початкового масиву значеннями зі списку ініціалізації
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
			// Видаляємо всі існуючі елементи
			delete[] m_data;

			// Перевиділяємо масив
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
		// Нам не потрібно тут присвоювати значення null для m_data чи виконувати m_length = 0, тому що об'єкт знищиться відразу після виконання цієї функції
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
	ArrayInt array{ 7, 6, 5, 4, 3, 2, 1 }; // список ініціалізації
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 4, 9, 12, 15, 17, 19, 21 };

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	return 0;
}