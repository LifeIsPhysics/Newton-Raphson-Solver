#include "equations.h"
#include <cmath>

Equation::Equation(double x) : _x {x} {};

Sin::Sin(double x) : Equation(x) {}
double Sin::f() const { return std::sin(_x); }
double Sin::df() const { return std::cos(_x); }

Cos::Cos(double x) : Equation(x) {}
double Cos::f() const { return std::cos(_x); }
double Cos::df() const { return  - std::sin(_x); }

Tan::Tan(double x) : Equation(x) {}
double Tan::f() const { return std::tan(_x); }
double Tan::df() const { return 1 / std::pow( std::cos(_x), 2 ); }

Sec::Sec(double x) : Equation(x) {}
double Sec::f() const { return 1 / std::cos(_x); }
double Sec::df() const { return std::tan(_x) / std::cos(_x); }

Cosec::Cosec(double x) : Equation(x) {}
double Cosec::f() const { return 1 / std::sin(_x); }
double Cosec::df() const { return - std::cos(_x) / std::pow( std::sin(_x), 2 ); }

Cot::Cot(double x) : Equation(x) {}
double Cot::f() const { return 1 / std::tan(_x); }
double Cot::df() const { return - 1 / std::pow( std::sin(_x), 2 ); }

Exp::Exp(double x) : Equation(x){}
double Exp::f() const { return std::exp(_x); }
double Exp::df() const { return std::exp(_x); }

Log::Log(double x) : Equation(x) {}
double Log::f() const { return std::log(_x); }
double Log::df() const { return 1 / _x ; }
