#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace ariel{}


class Fraction
{
    private:
        int Numerator_;
        int Denominator_;


    public:

    // Constructor
    Fraction(int numerator, int denominator);
    Fraction(float num);
    Fraction();

    // getters
    int getNumerator() const;
    int getDenominator() const;

    // setters
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    // other methods
    int greatestCommonDivisor(int numerator, int denominator);
    void reduceFraction();
    float set3DigitsBeyondThePoint(float num);
    void increment();
    void decrement();
    float fracToFloat();

    // operator "+"
    Fraction operator+(const Fraction &other) const;
    friend Fraction operator+(const Fraction &fraction, float num);
    friend Fraction operator+(float num, const Fraction &fraction);

    // operator "-"
    Fraction operator-(const Fraction &other) const;
    friend Fraction operator-(const Fraction &fraction, float num);
    friend Fraction operator-(float num, const Fraction &fraction);

    // operator "*"
    Fraction operator*(const Fraction &other) const;
    friend Fraction operator*(const Fraction &fraction, float num);
    friend Fraction operator*(float num, const Fraction &fraction);

    // operator "/"
    Fraction operator/(const Fraction &other) const;
    friend Fraction operator/(const Fraction &fraction, float num);
    friend Fraction operator/(float num, const Fraction &fraction);

    // operator "=="
    bool operator==(const Fraction &other) const;
    friend bool operator==(const Fraction &fraction, float num);
    friend bool operator==(float num, const Fraction &fraction);

    // operator "!=" 
    bool operator!=(const Fraction &other) const;
    friend bool operator!=(const Fraction &fraction, float num);
    friend bool operator!=(float num, const Fraction &fraction);

    // operator ">"
    bool operator>(const Fraction &other) const;
    friend bool operator>(const Fraction &fraction, float num);
    friend bool operator>(float num, const Fraction &fraction);

    // operator "<"
    bool operator<(const Fraction &other) const;
    friend bool operator<(const Fraction &fraction, float num);
    friend bool operator<(float num, const Fraction &fraction);

    // operator ">="
    bool operator>=(const Fraction &other) const;
    friend bool operator>=(const Fraction &fraction, float num);
    friend bool operator>=(float num, const Fraction &fraction);

    // operator "<="
    bool operator<=(const Fraction &other) const;
    friend bool operator<=(const Fraction &fraction, float num);
    friend bool operator<=(float num, const Fraction &fraction);

    // operator "++"
    Fraction operator++(int paramForOverloading); // postfix(i++)
    Fraction& operator++(); // prefix(++i)

    // operator "--"
    Fraction operator--(int paramForOverloading); // postfix(i--)
    Fraction& operator--(); // prefix(--i)

    // operator "<<"
    friend ostream& operator<<(ostream &desiredOutput, const Fraction &fraction);

    // operator ">>"
    friend istream& operator>>(istream &desiredInput, Fraction &fraction);
};