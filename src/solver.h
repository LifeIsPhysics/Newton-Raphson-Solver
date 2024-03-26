#ifndef SOLVER_H
#define SOLVER_H

#include <cmath>
#include <functional>
#include <iostream>
#include <exception>

using Func1D = std::function<double(double)>;

double df(const Func1D& f, double x, double h=1e-12);

double solve(const Func1D& f, double x0, double tol=1e-12, unsigned maxNumIter=1000);

#endif /* SOLVER_H */
