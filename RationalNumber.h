#pragma once

class RationalNumber
{
public:
    RationalNumber(int n, int d);
    int getNumerator();
    int getDenominator();
    
private:
    int numerator;
    int denominator;

    void setNumerator(int n);
    void setDenominator(int d);
};