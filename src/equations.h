#ifndef EQUATION_H
#define EQUATION_H

#include <cmath>
#include <iostream>

class Equation{
protected:
    double _x{};

public:
    Equation(double x);
    virtual ~Equation() = default;

    virtual double f() const = 0;
    virtual double df() const = 0;
};


class Sin : public Equation{
public:
    Sin(double x);
    double f() const override;
    double df() const override;
};

class Cos : public Equation{
public:
    Cos(double x);
    double f() const override;
    double df() const override;
};

class Tan : public Equation{
public:
    Tan(double x);
    double f() const override;
    double df() const override;
};

class Sec : public Equation{
public:
    Sec(double x);
    double f() const override;
    double df() const override;
};

class Cosec : public Equation{
public:
    Cosec(double x);
    double f() const override;
    double df() const override;
};

class Cot : public Equation{
public:
    Cot(double x);
    double f() const override;
    double df() const override;
};

class Exp : public Equation{
public:
    Exp(double x);
    double f() const override;
    double df() const override;
};

class Log : public Equation{
public:
    Log(double x);
    double f() const override;
    double df() const override;
};

#endif /* EQUATION_H */
