#include "Solver.h"

Solver::Solver(Equation& eq, double x0, double tol, unsigned N)
        : _equation { eq }, _x0 { x0 }, _tolerance { tol }, _maxIterationNumber { N }
{}

double Solver::solve() {
    double dx{};
    for(auto i{0u}; i < _maxIterationNumber; ++i)
    {   
        dx = - _equation.f(_x0) / _equation.df(_x0);
        
        // backtracking, if function increases after update
        while( std::abs( _equation.f(_x0 + dx) ) > std::abs( _equation.f(_x0) ) ) 
            dx /= 2;
        
        _x0 = _x0 + dx;

        if( std::abs( _equation.f(_x0) ) < _tolerance ) return _x0;
    }
    throw( std::runtime_error("The solution did not converge.") );
}

