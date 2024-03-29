#ifndef SOLVER_H
#define SOLVER_H

#include <exception>

#include "Equation.h"


class Solver{
private:
    Equation _equation { nullptr };
    double _x0 {};
    double _tolerance { 1e-8 };
    unsigned _maxIterationNumber { 5000u };

public:
    Solver(Equation& eq, double x0, double tol=1e-12, unsigned N=5000);
    double solve();
};

#endif /* SOLVER_H */
