#pragma once
#include <string>

using namespace std;

class RationalNumberException
{
public:
    RationalNumberException(string m) {exceptionMessage = m;}
    string getExceptionMessage() {return exceptionMessage;}
private:
    string exceptionMessage;
};