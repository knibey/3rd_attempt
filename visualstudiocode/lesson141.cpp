#include <iostream>
 
class Fraction1
{
private:
    int m_numerator;
    int m_denominator;
 
public:
    Fraction1(int numerator=0, int denominator=1):
        m_numerator(numerator), m_denominator(denominator)
    {
        // Ми помістили метод reduce() в конструктор, щоб переконатися, що всі дроби, які у нас є, будуть зменшені!
        // Всі дроби, які перезаписані, повинні бути повторно зменшені
        reduce();
    }
 
    // Робимо функцію nod() статичною, щоб вона могла бути частиною класу Fraction1 і при цьому, для її використання, нам не потрібно було створювати об'єкт класу Fraction1
    static int nod(int a, int b)
    {
        return b == 0 ? a : nod(b, a % b);
    }
 
    void reduce()
    {
        int nod = Fraction1::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }
 
    friend Fraction1 operator*(const Fraction1 &f1, const Fraction1 &f2);
    friend Fraction1 operator*(const Fraction1 &f1, int value);
    friend Fraction1 operator*(int value, const Fraction1 &f1);
 
    friend std::ostream& operator<< (std::ostream& out, const Fraction1& Fraction1);
    friend std::istream& operator>> (std::istream& in, Fraction1& Fraction1);

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }
};
 
Fraction1 operator*(const Fraction1 &f1, const Fraction1 &f2)
{
    return Fraction1(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
 
Fraction1 operator*(const Fraction1 &f1, int value)
{
    return Fraction1(f1.m_numerator * value, f1.m_denominator);
}
 
Fraction1 operator*(int value, const Fraction1 &f1)
{
    return Fraction1(f1.m_numerator * value, f1.m_denominator);
}

std::ostream& operator<< (std::ostream& out, const Fraction1& fraction1) {
    out << fraction1.m_numerator << "/" << fraction1.m_denominator;
    return out;
}

std::istream& operator>> (std::istream& in, Fraction1& fraction1) {
    char c;

    in >> fraction1.m_numerator;
    in >> c;
    in >> fraction1.m_denominator;

    fraction1.reduce();

    return in;
}


int main()
{
 
    Fraction1 f1;
    std::cout << "Enter Fraction1 1: ";
    std::cin >> f1;
 
    Fraction1 f2;
    std::cout << "Enter Fraction1 2: ";
    std::cin >> f2;
 
    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
 
    return 0;
}