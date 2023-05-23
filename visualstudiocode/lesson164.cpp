#include <iostream>

class Fruit {
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name = "", std::string color = "") : m_name(name), m_color(color) {}

	std::string getName() const {
		return m_name;
	}

	std::string getColor() const {
		return m_color;
	}
};

class Apple : public Fruit {
private:
	double m_fiber;
public:
	Apple(std::string name, std::string color, double fiber = 0) : Fruit(name, color), m_fiber(fiber) {}

	double getFiber() const {
		return m_fiber;
	}

	friend std::ostream& operator<<(std::ostream& out, const Apple& app) {
		out << "Apple(" << app.getName() << ", " << app.getColor() << ", " << app.getFiber() << ")\n";

		return out;
	}
};

class Banana : public Fruit {
public:
	Banana(std::string name, std::string color) : Fruit(name, color) {}

	friend std::ostream& operator<<(std::ostream& out, const Banana& banana) {
		out << "Banana(" << banana.getName() << ", " << banana.getColor() << ")\n";

		return out;
	}
};

int mainlesson164()
{
	const Apple a("Red delicious", "red", 7.3);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
 
	return 0;
}