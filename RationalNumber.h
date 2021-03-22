#pragma once
#include <string>

using namespace std;

class RationalNumber
{
public:
    RationalNumber(int n, int d);
    int getNumerator();
    int getDenominator();
    int getReducedNumerator();
    int getReducedDenominator();
    string toString();
    string toStringReduced();
    bool operator==(RationalNumber& other);
    bool operator!=(RationalNumber& other);
private:
    int numerator;
    int denominator;
    int reducedNumerator;
    int reducedDenominator;
    bool isNumberNegative;

    void setNumerator(int n);
    void setDenominator(int d);
    void setReducedNumerator(int n);
    void setReducedDenominator(int d);

    void reduce();
    void setIsNumberNegative(int n, int d);
    bool getIsNumberNegative();
};