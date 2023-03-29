#include <iostream>

class Something
{
private:
	double m_a, m_b, m_c;

public:
	Something(double a = 0.0, double b = 0.0, double c = 0.0) :
		m_a(a), m_b(b), m_c(c)
	{
	}

	// ���������� ��'��� ����� Something � ��'�����
	Something operator- () const
	{
		return Something(-m_a, -m_b, -m_c);
	}

	// ��������� true, ���� ���������������� �������� �� �������������, � ������������ ������� - false
	bool operator! () const
	{
		return (m_a == 0.0 && m_b == 0.0 && m_c == 0.0);
	}

	Something operator+ () const {
		return Something(m_a, m_b, m_c);
	}

	double getA() { return m_a; }
	double getB() { return m_b; }
	double getC() { return m_c; }
};

int mainlesson143()
{
	Something something; // ������������� ����������� �� ������������� � ���������� 0.0, 0.0, 0.0

	if (!something)
		std::cout << "Something is null.\n";
	else
		std::cout << "Something is not null.\n";

	return 0;
}