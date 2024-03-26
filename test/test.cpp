#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "helper.h"
#include "doctest.h"
#include "../src/solver.h"
#include <iostream>

TEST_CASE("Testing the Newton-Raphson Algorithm..."){
    auto f1 = [](double x) { return x*x; };
    auto f2 = [](double x) { return x*x*x - 2.0; };
    double x0  = 10.0;
    double x_res1 { solve(f1, x0, 1e-16, 5000) };
    double x_res2 { solve(f2, x0, 1e-16, 5000) };

    bool xSquared = equals(x_res1, 0.0, 1e-8, 1e-8); 
    bool xCubedminustwo = equals(x_res2, std::cbrt(2.0), 1e-8, 1e-8); 
    CHECK(xSquared);
    CHECK(xCubedminustwo);
    std::cout << "The root for x^2 was found at " << x_res1 << '\n';
    std::cout << "The root for x^3 - 2 was found at " << x_res2 << '\n';
}

