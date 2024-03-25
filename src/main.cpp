#include <iostream>
#include <cmath>
#include <functional>

auto func = [](double x)
{ return x * x - 4; };

double df(double x, double h=1e-12){
    return (func(x + h/2) - func(x - h/2)) / h;
}

double solve(const std::function<double(double)>& f, double x0, double tol=1e-12, unsigned maxNumIter=5000){
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

int main(){
    double x0;
    std::cout << "Give me an initial guess for the root of the function x^2 - 4: ";
    std::cin >> x0;

    double tol;
    std::cout << "Give me an tolerance (default: 1e-12): ";
    std::cin >> tol;

    unsigned maxNumIter;
    std::cout << "Give me an max iteration number (default: 5000): ";
    std::cin >> maxNumIter;

    double x_res { solve(func, x0, tol, maxNumIter) };
    std::cout << "The root of the function is " << x_res << '\n';

    return 0;
}
