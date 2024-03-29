#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <string_view>
#include <cmath>

#include "helper.h"
#include "doctest.h"
#include "Solver.h"
#include "Equation.h"

std::vector<std::pair<Func1D, double>> test_cases {
    {[](double x){ return std::pow(x, 3) * (x * x - 2);}, 2.0},
    {[](double x){ return std::pow(x, 14) * std::sin(x);}, 69.0},
    {[](double x){ return std::pow(x, M_PI) * std::cos(x);}, 22.0},
    {[](double x){ return x * std::tan(x);}, 1.0},
    {[](double x){ return x * x * std::exp(x);}, 1.0},
    {[](double x){ return x * std::log(x);}, 4.0}
};


TEST_CASE("Testing functions."){
    for(const auto& [f, x0] : test_cases){
            Equation eq(f);
            Solver solver(eq, x0, 1e-12, 100000);
            double x_res;
            try{
                x_res = solver.solve();
                CHECK(equals(f(x_res), 0.0));
            } catch(std::exception& e){
                std::cout << e.what() << std::endl;
            }
    }
}


