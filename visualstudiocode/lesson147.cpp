#include <iostream>
#include <string>
#include <cassert>

class Mystring {
private:
    std::string m_string;

public:
    Mystring(const std::string string="") : m_string(string) {}

    std::string& operator+= (const std::string& string) {
        return m_string += string;
    }

    std::string operator() (const int index, const int length) {
        std::string temp;

        for (int i = 0; i < length; ++i) {
            temp += m_string[index + i];
        }

        return temp;
    }
};

int mainlesson147()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 6); // �������� � 7-�� ������� (�������) � ��������� ������� 6 �������

    return 0;
}