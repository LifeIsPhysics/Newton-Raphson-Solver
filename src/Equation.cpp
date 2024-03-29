#include "Equation.h"

Equation::Equation(const Func1D& f): _f{f} {}

double Equation::f(double x) const { return _f(x); }
double Equation::df(double x, double h) const { 
    return ( _f(x + h/2) - _f(x - h/2) ) / h;
}
