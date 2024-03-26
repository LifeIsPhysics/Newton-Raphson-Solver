#include "solver.h"

double df(const Func1D& f, double x, double h)
{
    return (f(x + h/2) - f(x - h/2)) / h;
}

double solve(const Func1D& f, double x0, double tol, unsigned maxNumIter)
{
    double dx{};
    for(auto i{0u}; i < maxNumIter; ++i)
    {
        dx = - f(x0) / df(f, x0);
        
        // backtracking, if function increases after update
        while( std::abs( f(x0 + dx) ) > std::abs( f(x0) ) ) 
            dx /= 2;
        
        x0 += dx;

        if( std::abs( f(x0) ) < tol ) return x0;
    }
    throw( std::runtime_error("The function did not converge.") );
}

