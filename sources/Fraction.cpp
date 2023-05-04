#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstdlib>
#include "Fraction.hpp" 

using namespace std;

#define THOUSAND 1000
#define ZERO 0
#define ONE 1
#define MAX_INT 2147483647
#define MIN_INT -2147483648


// ### Constructors ###

// constructor
Fraction::Fraction(int numerator, int denominator) : Numerator_(numerator), Denominator_(denominator)
{
    // Numerator and Denominator are valid
    if( ((numerator >= MIN_INT) && (numerator <= MAX_INT)) && ((denominator >= MIN_INT) && (denominator <= MAX_INT)) )
    {
        // in case denominator equal to zero - throw an exception
        if(denominator == 0)
        {
            throw invalid_argument("Denominator can't be 0, you can't devide by zero.\n");
            return;
        }

        // reduce the fraction
        reduceFraction();
    }

    // Numerator and Denominator are invalid - overflow
    else
    {
        throw overflow_error("Numerator/Denominator overflow\n");
    }
}

// constructor that takes a float
Fraction::Fraction(float num)
{
    // round num to 3 digits beyond the decimal point for accuarcy
    float round3Digits = set3DigitsBeyondThePoint(num);
    
    // represent the float without decimal point and cast it to int,
    //  then represent it as numerator and denominator
    int numerator = static_cast<int>( round3Digits * THOUSAND );
    int denominator = THOUSAND;

    // set the data members
    this->Numerator_ = numerator;
    this->Denominator_ = denominator;

    // reduce the fraction
    reduceFraction();
}

// default constructor
Fraction::Fraction() : Numerator_(ZERO), Denominator_(ONE) {}


// ### Getters ###

// getter method for the "Numerator" data member
int Fraction::getNumerator() const
{
    return this->Numerator_;
}

// getter method for the "Denominator" data member
int Fraction::getDenominator() const
{
    return this->Denominator_;
}

// ### Setters ###

// setter method for the "Numerator" data member
void Fraction::setNumerator(int numerator)
{
    this->Numerator_ = numerator;
}

// setter method for the "Denominator" data member
void Fraction::setDenominator(int denominator)
{
    this->Denominator_ = denominator;
}

// this method returns the the largest common divisor of the numerator and the denominator
int Fraction::greatestCommonDivisor(int numerator, int denominator)
{
    // the absolute value of the numerator and denominator
    int absoluteNum = abs(numerator);
    int absoluteDeno = abs(denominator);

    // the largest common divisor of both the numerator and denominator
    int greatestCommonDivisor = __gcd(absoluteNum, absoluteDeno);
    
    return greatestCommonDivisor;
} 

// this method reduce the fraction object
void Fraction::reduceFraction()
{
    // if just the Denominator is negative - change it so just the numerator is negative
    // if both the numerator and denominator are negative - change both to positive
    if( ( (this->Numerator_ > 0) && (this->Denominator_ < 0) ) || ( (this->Numerator_ < 0) && (this->Denominator_ < 0) ) )
    {
        this->Numerator_ = this->Numerator_ / -1;
        this->Denominator_ = this->Denominator_ / -1;
    }

    // the largest common divisor
    int gcd = greatestCommonDivisor(this->Numerator_, this->Denominator_);

    // if largest common divisor isn't 1 - divide both the numerator and
    // the denominator by the gcd to get the reduced form of the fraction
    if(gcd != 1)
    {
        this->Numerator_ = this->Numerator_ / gcd;
        this->Denominator_ = this->Denominator_ / gcd;
    }
}

// this method round float number up to 3 digits beyond the point
float Fraction::set3DigitsBeyondThePoint(float num)
{
    // multiply num by 1000 and round the 
    // number without decimal point
    float round = roundf( num * THOUSAND );

    // change the number into float
    float ret = round / THOUSAND;

    return ret;
}

// this method increment the fraction by 1
void Fraction::increment()
{
    *this = *this + 1;
}

// this method decrement the fraction by 1
void Fraction::decrement()
{
    *this = *this - 1;
}

// this method cast fraction into float
float Fraction::fracToFloat()
{
    float num = static_cast<float>(this->getNumerator());
    float deno = static_cast<float>(this->getDenominator());

    return num / deno;
}


// operator "+"
Fraction Fraction::operator+(const Fraction &other) const
{
    int deno1 = this->Denominator_;
    int deno2 = other.getDenominator();
    int nume1 = this->Numerator_;
    int nume2 = other.getNumerator();

    // the common Denominator of the 2 numbers
    int commonDenominator = deno1 * deno2;

    // the numerator after the calculation
    int commonNumerator = (nume1 * deno2) + (nume2 * deno1);

    // the calculation result represent as a reduced fraction
    Fraction retFrac(commonNumerator, commonDenominator);
    retFrac.reduceFraction();

    return retFrac;
}

Fraction operator+(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction + other;
}

Fraction operator+(float num, const Fraction &fraction)
{
    return fraction + num;
}

// operator "-"
Fraction Fraction::operator-(const Fraction &other) const
{
    int deno1 = this->Denominator_;
    int deno2 = other.getDenominator();
    int nume1 = this->Numerator_;
    int nume2 = other.getNumerator();

    // the common Denominator of the 2 numbers
    int commonDenominator = deno1 * deno2;

    // the numerator after the calculation
    int commonNumerator = (nume1 * deno2) - (nume2 * deno1);

    // the calculation result represent as a reduced fraction
    Fraction retFrac(commonNumerator, commonDenominator);
    retFrac.reduceFraction();

    return retFrac;
}

Fraction operator-(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction - other;
}

Fraction operator-(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other - fraction;
}

// operator "*"
Fraction Fraction::operator*(const Fraction &other) const
{
    int deno1 = this->Denominator_;
    int deno2 = other.getDenominator();
    int nume1 = this->Numerator_;
    int nume2 = other.getNumerator();

    // the common Denominator of the 2 numbers
    int commonDenominator = deno1 * deno2;

    // the numerator after the calculation
    int commonNumerator = nume1 * nume2;

    // the calculation result represent as a reduced fraction
    Fraction retFrac(commonNumerator, commonDenominator);
    retFrac.reduceFraction();

    return retFrac;
}

Fraction operator*(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction * other;
}

Fraction operator*(float num, const Fraction &fraction)
{
    return fraction * num;
}

// operator "/"
Fraction Fraction::operator/(const Fraction &other) const
{
    int deno1 = this->Denominator_;
    int deno2 = other.getDenominator();
    int nume1 = this->Numerator_;
    int nume2 = other.getNumerator();

    // the common Denominator of the 2 numbers(multiply by the inverse)
    int commonDenominator = deno1 * nume2;

    // the numerator after the calculation(multiply by the inverse)
    int commonNumerator = nume1 * deno2;

    // if the common Denominator is equal to 0 after the division throw an exception
    if(commonDenominator == 0)
    {
        throw runtime_error("Can't divide by fraction with numerator equal to 0\n");
    }

    // the calculation result represent as a reduced fraction
    Fraction retFrac(commonNumerator, commonDenominator);
    retFrac.reduceFraction();

    return retFrac;
}

Fraction operator/(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction / other;
}

Fraction operator/(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other / fraction;
}

// operator "=="
bool Fraction::operator==(const Fraction &other) const
{   
    // if both the numerators are 0, the denominators do not affect the result
    if( this->Numerator_ == 0 && other.getNumerator() == 0 ) return true;

    // if the numerator and the denominator of both the fractions is equal return true
    return ( this->Numerator_ == other.getNumerator() ) && ( this->Denominator_ == other.getDenominator() );
}

bool operator==(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction == other;
}

bool operator==(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other == fraction;
}

// operator "!="
bool Fraction::operator!=(const Fraction &other) const
{
    // if the numerator or the denominator of both the fractions is different return true
    return ( this->Numerator_ != other.getNumerator() ) || ( this->Denominator_ != other.getDenominator() );
}

bool operator!=(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction != other;
}

bool operator!=(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other != fraction;
}

// operator ">"
bool Fraction::operator>(const Fraction &other) const
{
    // numerator and denominator of both the fractions
    int deno1 = this->Denominator_;
    int deno2 = other.getDenominator();
    int nume1 = this->Numerator_;
    int nume2 = other.getNumerator();

    // widening the fractions into fractions
    // with the same denominator, in order to compare numerators
    int commonNumerator1 = nume1 * deno2;
    int commonNumerator2 = nume2 * deno1;

    return (commonNumerator1 > commonNumerator2);
}

bool operator>(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction > other;
}

bool operator>(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other > fraction;
}

// operator "<"
bool Fraction::operator<(const Fraction &other) const
{
    // numerator and denominator of both the fractions
    int deno1 = this->Denominator_;
    int deno2 = other.getDenominator();
    int nume1 = this->Numerator_;
    int nume2 = other.getNumerator();

    // widening the fractions into fractions
    // with the same denominator, in order to compare numerators
    int commonNumerator1 = nume1 * deno2;
    int commonNumerator2 = nume2 * deno1;

    return (commonNumerator1 < commonNumerator2);
}

bool operator<(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction < other;
}

bool operator<(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other < fraction;
}

// operator ">="
bool Fraction::operator>=(const Fraction &other) const
{
    // negative of < is >=
    return !(*this < other);
}

bool operator>=(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction >= other;
}

bool operator>=(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other >= fraction;
}

// operator "<="
bool Fraction::operator<=(const Fraction &other) const
{
    // negative of > is <=
    return !(*this > other);
}

bool operator<=(const Fraction &fraction, float num)
{
    // turn the float into a fraction
    Fraction other(num);

    return fraction <= other;
}

bool operator<=(float num, const Fraction &fraction)
{
    // turn the float into a fraction
    Fraction other(num);

    return other <= fraction;
}

// operator "++"
Fraction Fraction::operator++(int paramForOverloading) // postfix
{
    // save the fraction before the incrementation
    Fraction prev = *this;

    // increment the fraction(this) by 1
    increment();

    // reduce the fraction(this)
    reduceFraction();
    
    // return the fraction(this) before the change
    return prev;
}

Fraction& Fraction::operator++() // prefix
{
    // increment the fraction(this) by 1
    increment();

    // reduce the fraction(this)
    reduceFraction();

    // return the fraction(this) after the change
    return *this;
}

// operator "--"
Fraction Fraction::operator--(int paramForOverloading) // postfix
{
    // save the fraction before the incrementation
    Fraction prev = *this;

    // decrement the fraction(this) by 1
    decrement();

    // reduce the fraction(this)
    reduceFraction();
    
    // return the fraction(this) before the change
    return prev;
}

Fraction& Fraction::operator--() // prefix
{
    // decrement the fraction(this) by 1
    decrement();

    // reduce the fraction(this)
    reduceFraction();

    // return the fraction(this) after the change
    return *this;
}

// operator "<<"
ostream& operator<<(ostream &desiredOutput, const Fraction &fraction)
{
    // print the fraction in a form numerator/denominator
    desiredOutput << fraction.getNumerator() << "/" << fraction.getDenominator();

    return desiredOutput;
}

// operator ">>"
istream& operator>>(istream &desiredInput, Fraction &fraction)
{
    int nume;
    int deno;

    // the input stored in "nume" and "deno" variables
    desiredInput >> nume >> deno; 

    // if denominator got 0 as input - throw an exception
    // or:
    // check if the input is not in the expected format, if so - throw an exception
    if(deno == 0 || desiredInput.fail())
    {
        throw runtime_error("The numerator can't get zero as input or, the current input isn't valid\n");
    }

    // create a fraction using those variables and 
    // assigned it to the fraction that passed as reference 
    Fraction temp(nume, deno);
    fraction = temp;

    // return the istream object in case of chaining input operations
    return desiredInput;
}