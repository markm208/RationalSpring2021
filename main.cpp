#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
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
    SECTION("First Test")
    {
        REQUIRE(1 == 1);
    }
}