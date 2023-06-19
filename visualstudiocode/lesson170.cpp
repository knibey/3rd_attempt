#include <iostream>

class Animal
{
protected:
    std::string m_name;
    const char* m_speak;

    // �� ������ ��� ����������� protected, ���� �� �� ������, ��� ����������� ���������� ��'���� ����� Animal �������,
    // ��� ������, ��� � ������� ����� ������ ��� ��������
    Animal(std::string name, const char* speak)
        : m_name(name), m_speak(speak)
    {
    }

public:
    std::string getName() { return m_name; }
    const char* speak() { return m_speak; }
};

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name, "Meow")
    {
    }

    const char* speak() { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name, "Woof")
    {
    }

    const char* speak() { return "Woof"; }
};

int mainlesson170()
{
    Cat matros("Matros"), ivan("Ivan"), martun("Martun");
    Dog barsik("Barsik"), tolik("Tolik"), tyzik("Tyzik");

    // ��������� ����� ��������� �� ���� ��'���� Cat � Dog
    Animal* animals[] = { &matros, &ivan, &martun, &barsik, &tolik, &tyzik };
    for (int iii = 0; iii < 6; iii++)
        std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';

    return 0;
}