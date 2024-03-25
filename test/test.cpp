//
// Created by berke on 3/25/24.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>
#include <functional>

auto f = [](double x)
{ return x * x - 4; };

double df(double x, double h=1e-12){
    return (f(x + h/2) - f(x - h/2)) / h;
}

double solve(const std::function<double(double)>& f, double x0, double tol=1e-8, unsigned maxNumIter=5000){
    double dx{};
    // std::cout << tol << " " << maxNumIter << '\n';
    for(auto i=0u; i < maxNumIter; ++i){
        dx = - f(x0) / df(x0);

        while(std::pow(f(x0 + dx), 2) > std::pow(f(x0 + dx), 2)) x0 += dx / 2;
        // bool cond = std::abs(f(x0)) < tol;
        // std::cout << x0 << " " << std::abs(f(x0)) << " " << tol << " " << cond << '\n';
        if(std::abs(f(x0)) < tol) return x0;

        x0 = x0 + dx;
    }
    std::cout << "Root finding converge.\n";
    return x0;
}

bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    // Knuth's algorithm for floating point comparison
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

bool equals(double a, double b, double absEpsilon=1e-8, double relEpsilon=1e-8)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) < absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

TEST_CASE("Testing the Newton-Raphson-Solver"){
    double init_guess = 1.0;
    double tol = 1e-12;
    unsigned maxNumIter = 5000;
    double x1 {2}, x2{-2};
    auto x_res {solve(f, init_guess, tol, maxNumIter)};
    bool cond = equals(x_res, x1) || equals(x_res, x2);
    CHECK(cond);
}
