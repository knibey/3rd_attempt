#include <iostream>

class Fraction {
private:
    int m_chiselnik = 0;
    int m_znamennik = 1;

public:
    Fraction(int chiselnik=0, int znamennik=1) : m_chiselnik(chiselnik), m_znamennik(znamennik) {
        reduce();
    }

    void print() {
        std::cout << m_chiselnik << "/" << m_znamennik << std::endl;
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

    static int nod(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }

    void reduce() {
        int nod = Fraction::nod(m_chiselnik, m_znamennik);
        m_chiselnik /= nod;
        m_znamennik /= nod;
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.m_chiselnik * f2.m_chiselnik, f1.m_znamennik * f2.m_znamennik);
}

Fraction operator*(const Fraction& f1, int value) {
    return Fraction(f1.m_chiselnik * value, f1.m_znamennik);
}

Fraction operator*(int value, const Fraction& f1) {
    return Fraction(f1.m_chiselnik * value, f1.m_znamennik);
}

int mainlesson139()
{
    Fraction f1(3, 4);
    f1.print();

    Fraction f2(2, 7);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 3;
    f4.print();

    Fraction f5 = 3 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    return 0;
}