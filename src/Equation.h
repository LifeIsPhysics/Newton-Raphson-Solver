#ifndef EQUATION_H
#define EQUATION_H

#include <cmath>
#include <iostream>
#include <functional>

using Func1D = std::function<double(double)>;

class Equation{
private:
    const Func1D _f;

public:
    Equation(const Func1D& f);

    double f(double x) const;
    double df(double x, double h=1e-8) const;
};

#endif /* EQUATION_H */

