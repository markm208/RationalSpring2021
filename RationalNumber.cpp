#include "RationalNumber.h"
#include "RationalNumberException.h"

RationalNumber::RationalNumber(int n, int d)
{
    //store the absolute value of the passed in numerator and denominator
    setNumerator(abs(n));
    setDenominator(abs(d));
    setReducedNumerator(abs(n));
    setReducedDenominator(abs(d));
    //capture the sign of the numbers
    setIsNumberNegative(n, d);
    //reduce
    reduce();
}
//--
bool RationalNumber::operator==(RationalNumber& other)
{
    bool retVal = false;

    if (reducedNumerator == other.reducedNumerator &&
        reducedDenominator == other.reducedDenominator)
    {
        if (getIsNumberNegative() == other.getIsNumberNegative())
        {
            retVal = true;
        }
    }

    return retVal;
}
//--
bool RationalNumber::operator!=(RationalNumber& other)
{
    return !(*this == other);
}
//--
void RationalNumber::setIsNumberNegative(int n, int d)
{
    if( (n < 0 && d > 0) || (n >= 0 && d < 0) )
    {
        isNumberNegative = true;
    }
    else
    {
        isNumberNegative = false;
    }
}
//--
bool RationalNumber::getIsNumberNegative()
{
    return isNumberNegative;
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
void RationalNumber::setReducedNumerator(int n)
{
    reducedNumerator = n;
}
//--
void RationalNumber::setReducedDenominator(int d)
{
    if(d != 0)
    {
        reducedDenominator = d;
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
    int retVal = numerator;
    if(getIsNumberNegative())
    {
        retVal = -retVal;
    }
    return retVal;
}
//--
int RationalNumber::getDenominator()
{
    return denominator;
}
//--
int RationalNumber::getReducedNumerator()
{
    int retVal = reducedNumerator;
    if(getIsNumberNegative())
    {
        retVal = -retVal;
    }
    return retVal;
}
//--
int RationalNumber::getReducedDenominator()
{
    return reducedDenominator;
}
//--
string RationalNumber::toString()
{
    string retVal;
    if(getIsNumberNegative())
    {
        retVal = "-";
    }

    if(getNumerator() >= getDenominator())
    {
        retVal = to_string(getNumerator() / getDenominator());
        if(getNumerator() % getDenominator() != 0)
        {
            retVal += " ";
            retVal += to_string(getNumerator() % getDenominator());
            retVal += "/";
            retVal += to_string(getDenominator());
        }
    }
    else
    {
        retVal = to_string(getNumerator()) + "/" + to_string(getDenominator());
    }  
    return retVal;
}
//--
string RationalNumber::toStringReduced()
{
    string retVal;
    if(getIsNumberNegative())
    {
        retVal = "-";
    }

    if(getReducedNumerator() >= getReducedDenominator())
    {
        retVal = to_string(getReducedNumerator() / getReducedDenominator());
        if(getReducedNumerator() % getReducedDenominator() != 0)
        {
            retVal += " ";
            retVal += to_string(getReducedNumerator() % getReducedDenominator());
            retVal += "/";
            retVal += to_string(getReducedDenominator());
        }
    }
    else
    {
        retVal = to_string(getReducedNumerator()) + "/" + to_string(getReducedDenominator());
    }
    return retVal;
}
//--
void RationalNumber::reduce()
{
    int lesserOfTwo;

    if(numerator < denominator)
    {
        lesserOfTwo = numerator;
    }
    else
    {
        lesserOfTwo = denominator;
    }

    for(int potentialDivisor = lesserOfTwo;potentialDivisor >= 2;potentialDivisor--)
    {
        if(numerator % potentialDivisor == 0 &&
           denominator % potentialDivisor == 0)
        {
            setReducedNumerator(numerator / potentialDivisor);
            setReducedDenominator(denominator / potentialDivisor);
            break;
        }
    }
}