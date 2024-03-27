#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "helper.h"
#include "doctest.h"
#include "equations.h"

TEST_CASE("Testing Sine function."){
    double x { M_PI / 2 };
    double approximation { Sin(x).f() };
    double expectation   { 1.0 };
    CHECK(equals(approximation, expectation));
}

