#include <iostream>
#include <cmath>

class FixedPoint {
private:
    int16_t m_base;
    int8_t m_decimal;
public:
    FixedPoint(int16_t base = 0, int8_t decimal = 0) : m_base(base), m_decimal(decimal) {
        if (m_base < 0.0 || m_decimal < 0.0) {
            if (m_base > 0.0) {
                m_base = -m_base;
            }

            if (m_decimal > 0.0) {
                m_decimal = -m_decimal;
            }
        }
    }

    FixedPoint(double value) {
        m_base = static_cast<int16_t>(value);
        m_decimal = static_cast<int8_t>(round((value-m_base)*100));
    }

    operator double() const {
        return m_base + static_cast<double>(m_decimal)/100;
    }

    friend std::ostream& operator<< (std::ostream& out, FixedPoint& fp) {
        out << static_cast<double>(fp);
        return out;
    }

    friend bool operator==(const FixedPoint& fp1, const FixedPoint& fp2) {
        return (fp1.m_base == fp2.m_base) && (fp1.m_decimal == fp2.m_decimal);
    }

    friend std::istream& operator >> (std::istream& in, FixedPoint& fp) {
        double d;
        in >> d;
        fp = FixedPoint(d);

        return in;
    }

    FixedPoint operator-() {
        return FixedPoint(-m_base, -m_decimal);
    }

    friend FixedPoint operator+(const FixedPoint &fp1, const FixedPoint &fp2) {
        return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
    }

};

void SomeTest()
{
    std::cout << std::boolalpha;
    std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // обидва значення додатні, ніякого переповнення
    std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // обидва значення додатні, переповнення
    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // обидва значення від'ємні, ніякого переповнення
    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // обидва значення від'ємні, переповнення
    std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // друге значення від'ємне, ніякого переповнення
    std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // друге значення від'ємне, можливе переповнення
    std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // перше значення від'ємне, ніякого переповнення
    std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // перше значення від'ємне, можливе переповнення
}

int maintopic9_test4()
{
    SomeTest();

    FixedPoint a(-0.48);
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // введіть 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}