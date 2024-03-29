#include <iostream>
#include <iomanip>
#include "Solver.h"
#include "Equation.h"

auto func = [](double x)
    { return x * x - 2; };

int main(){
    double x0;
    std::cout << "Give me an initial guess for the root of the function x^2 - 2: ";
    std::cin >> x0;

    double tol;
    std::cout << "Give me a tolerance (default: 1e-8): ";
    std::cin >> tol;

    unsigned maxNumIter;
    std::cout << "Give me a max iteration number (default: 1000): ";
    std::cin >> maxNumIter;
    
    Equation eq {[](double x){ return x * x - 2; }};
    try{
        Solver solver(eq, x0, tol, maxNumIter);
        double x_res { solver.solve() };
        std::cout << "The root of the function is " << std::setprecision(9) << x_res << '\n';
    } catch(std::exception& e){
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
