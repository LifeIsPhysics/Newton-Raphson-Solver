#include "solver.h"

double df(const IntegrableFunc1D& f, double x, double h){
    return (f(x + h/2) - f(x - h/2)) / h;
}

double solve(const IntegrableFunc1D& f, double x0, double tol, unsigned maxNumIter){
    double dx{};
    // std::cout << tol << " " << maxNumIter << '\n';
    for(auto i=0u; i < maxNumIter; ++i){
        dx = - f(x0) / df(f, x0);
        
        // backtracking
        while(std::pow(f(x0 + dx), 2) > std::pow(f(x0), 2)) x0 += dx / 2;
        
        // update x0
        x0 = x0 + dx;
        
        if(std::abs(f(x0)) < tol) return x0;

    }
    return x0;
}
