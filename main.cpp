#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "RationalNumber.h"
#include "RationalNumberException.h"

using namespace std;

int main()
{
    cout<<"Rational Number Code"<<endl;

    Catch::Session().run();

    return 0;
}
//--
TEST_CASE("Rational Numbers")
{
    SECTION("Constructors")
    {
        RationalNumber num1(1, 2);
        REQUIRE(num1.getNumerator() == 1);
        REQUIRE(num1.getDenominator() == 2);

        RationalNumber num2(4, 6);
        REQUIRE(num2.getNumerator() == 4);
        REQUIRE(num2.getDenominator() == 6);

        try
        {
            RationalNumber num3(1, 0);
            FAIL();
        }
        catch(RationalNumberException ex)
        {
            SUCCEED();
        }
    }
}