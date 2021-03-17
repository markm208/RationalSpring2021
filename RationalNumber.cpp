#include "RationalNumber.h"
#include "RationalNumberException.h"

RationalNumber::RationalNumber(int n, int d)
{
    setNumerator(n);
    setDenominator(d);
}
//--
void RationalNumber::setNumerator(int n)
{
    numerator = n;
}
//--
void RationalNumber::setDenominator(int d)
{
    if(d != 0)
    {
        denominator = d;
    }
    else
    {
        RationalNumberException ex("Cannot have a zero denominator");
        throw ex;
    }
}
//--
int RationalNumber::getNumerator()
{
    return numerator;
}
//--
int RationalNumber::getDenominator()
{
    return denominator;
}