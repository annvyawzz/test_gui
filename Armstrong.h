#ifndef ARMSTRONG_H
#define ARMSTRONG_H

#include <QString>
#include <QTextStream>
#include <cmath>

class Numbers {
private:
    int num;

public:
    Numbers() : num(0) {}

    void set(int value) { num = value; }

    int GCD(int other) const {
        int a = num;
        int b = other;
        while (a != 0 && b != 0) {
            if (a > b) a %= b;
            else b %= a;
        }
        return a + b;
    }

    int LCM(int other) const {
        int a = num;
        int b = other;
        int product = a * b;
        while (a != 0 && b != 0) {
            if (a > b) a %= b;
            else b %= a;
        }
        return product / (a + b);
    }

    bool isPrime() const {
        if (num < 2) return false;
        for (int i = 2; i <= std::sqrt(num); ++i)
            if (num % i == 0) return false;
        return true;
    }

    unsigned int countDigits() const {
        unsigned int n = std::abs(num);
        if (n == 0) return 1;
        unsigned int count = 0;
        while (n != 0) { n /= 10; count++; }
        return count;
    }

    bool isArmstrong() const {
        unsigned int sum = 0;
        unsigned int temp = std::abs(num);
        unsigned int original = temp;
        unsigned int digits = countDigits();
        while (temp != 0) {
            unsigned int digit = temp % 10;
            sum += static_cast<unsigned int>(std::pow(digit, digits));
            temp /= 10;
        }
        return num == 0 ? true : sum == original;
    }

    friend QTextStream& operator>>(QTextStream& in, Numbers& number) {
        in >> number.num;
        return in;
    }

    friend QTextStream& operator<<(QTextStream& out, const Numbers& number) {
        out << number.num;
        return out;
    }
};

#endif
