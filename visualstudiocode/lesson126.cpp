#include <string>
#include <iostream>

class Thing
{
private:
	std::string m_color = "blue";
	double m_radius = 20.0;

public:
	// Конструктор за замовчуванням без параметрів
	Thing()
	{
	}

	// Конструктор з параметром color (для radius надано значення за замовчуванням)
	Thing(const std::string& color) : m_color(color)
	{
	}

	// Конструктор з параметром radius (для color надано значення за замовчуванням)
	Thing(double radius) : m_radius(radius)
	{
	}

	// Конструктор з параметрами color і radius
	Thing(const std::string& color, double radius) : m_color(color), m_radius(radius)
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << " and radius: " << m_radius << '\n';
	}
};

int main()
{
	Thing defl;
	defl.print();

	Thing red("red");
	red.print();

	Thing thirty(30.0);
	thirty.print();

	Thing redThirty("red", 30.0);
	redThirty.print();

	return 0;
}