#ifndef SOLVER_H
#define SOLVER_H

#include <cmath>
#include <functional>

using IntegrableFunc1D = std::function<double(double)>;

double df(const IntegrableFunc1D& f, double x, double h=1e-12);

double solve(const IntegrableFunc1D& f, double x0, double tol=1e-12, unsigned maxNumIter=5000);

#endif /* SOLVER_H */
