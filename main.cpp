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
        REQUIRE(num1.getReducedNumerator() == 1);
        REQUIRE(num1.getReducedDenominator() == 2);

        RationalNumber num2(4, 6);
        REQUIRE(num2.getNumerator() == 4);
        REQUIRE(num2.getDenominator() == 6);
        REQUIRE(num2.getReducedNumerator() == 2);
        REQUIRE(num2.getReducedDenominator() == 3);

        RationalNumber num3(-4, 6);
        REQUIRE(num3.getNumerator() == -4);
        REQUIRE(num3.getDenominator() == 6);
        REQUIRE(num3.getReducedNumerator() == -2);
        REQUIRE(num3.getReducedDenominator() == 3);

        RationalNumber num4(4, -6);
        REQUIRE(num4.getNumerator() == -4);
        REQUIRE(num4.getDenominator() == 6);
        REQUIRE(num4.getReducedNumerator() == -2);
        REQUIRE(num4.getReducedDenominator() == 3);

        RationalNumber num5(-4, -6);
        REQUIRE(num5.getNumerator() == 4);
        REQUIRE(num5.getDenominator() == 6);
        REQUIRE(num5.getReducedNumerator() == 2);
        REQUIRE(num5.getReducedDenominator() == 3);

        RationalNumber num6(9, 5);
        REQUIRE(num6.getNumerator() == 9);
        REQUIRE(num6.getDenominator() == 5);
        REQUIRE(num6.getReducedNumerator() == 9);
        REQUIRE(num6.getReducedDenominator() == 5);

        RationalNumber num7(10, 5);
        REQUIRE(num7.getNumerator() == 10);
        REQUIRE(num7.getDenominator() == 5);
        REQUIRE(num7.getReducedNumerator() == 2);
        REQUIRE(num7.getReducedDenominator() == 1);

        RationalNumber num8(9, -5);
        REQUIRE(num8.getNumerator() == -9);
        REQUIRE(num8.getDenominator() == 5);
        REQUIRE(num8.getReducedNumerator() == -9);
        REQUIRE(num8.getReducedDenominator() == 5);

        RationalNumber num9(10, -5);
        REQUIRE(num9.getNumerator() == -10);
        REQUIRE(num9.getDenominator() == 5);
        REQUIRE(num9.getReducedNumerator() == -2);
        REQUIRE(num9.getReducedDenominator() == 1);

        RationalNumber num10(15, 100);
        REQUIRE(num10.getNumerator() == 15);
        REQUIRE(num10.getDenominator() == 100);
        REQUIRE(num10.getReducedNumerator() == 3);
        REQUIRE(num10.getReducedDenominator() == 20);

        try
        {
            RationalNumber num11(1, 0);
            FAIL();
        }
        catch(RationalNumberException ex)
        {
            SUCCEED();
        }
    }

    SECTION("toString tests")
    {
        RationalNumber num1(1, 2);
        RationalNumber num2(4, 6);
        RationalNumber num3(9, 5);
        RationalNumber num4(10, 5);
        RationalNumber num5(10, 10);
        RationalNumber num6(-4, 6);
        RationalNumber num7(4, -6);
        RationalNumber num8(-4, -6);
        RationalNumber num9(15, 100);

        REQUIRE(num1.toString() == "1/2");
        REQUIRE(num1.toStringReduced() == "1/2");
        REQUIRE(num2.toString() == "4/6");
        REQUIRE(num2.toStringReduced() == "2/3");
        REQUIRE(num3.toString() == "1 4/5");
        REQUIRE(num3.toStringReduced() == "1 4/5");
        REQUIRE(num4.toString() == "2");
        REQUIRE(num4.toStringReduced() == "2");
        REQUIRE(num5.toString() == "1");
        REQUIRE(num5.toStringReduced() == "1");
        REQUIRE(num6.toString() == "-4/6");
        REQUIRE(num6.toStringReduced() == "-2/3");
        REQUIRE(num7.toString() == "-4/6");
        REQUIRE(num7.toStringReduced() == "-2/3");
        REQUIRE(num8.toString() == "4/6");
        REQUIRE(num8.toStringReduced() == "2/3");
        REQUIRE(num9.toString() == "15/100");
        REQUIRE(num9.toStringReduced() == "3/20");
    }

    SECTION("Comparing Rationals")
    {
        RationalNumber num1(1, 2);
        RationalNumber num2(1, 2);
        RationalNumber num3(100, 200);
        RationalNumber num4(1, -2);
        RationalNumber num5(9, 5);

        REQUIRE((num1 == num2) == true);
        REQUIRE((num1 == num3) == true);
        REQUIRE((num1 != num4) == true);
        REQUIRE((num1 != num5) == true);
    }
}