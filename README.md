# Motivation
In maths, science and engineering, we often come to a situation, where we need to find the root of a function.
One of the most standard problems in quantum mechanics is to solve for the energies of an electron 
inside a one-dimensional finite square well. It can be shown that this scenario results in two
transcendental equation, whose roots can not be found with analytical methods. The Newton-Raphson root finding
algorithm exactly solves this problem, by first guessing the solution $x_0$ and then updating the guess
with the formula $x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$ iteratively until $|f(x_n)| < \epsilon$, where 
$\epsilon$ is a really small number ($\approx 10^{-8}$).

# Usage
Only a recent C++ compiler and CMake is needed to run this program. On Arch Linux, both of these dependencies
can be installed using `pacman`
```bash
sudo pacman -S gcc cmake
```
The repository can then be cloned with git on your local machine using HTTP/SSH
```bash
git clone https://github.com/LifeIsPhysics/Newton-Raphson-Solver.git # HTTP OR
git clone git@github.com:LifeIsPhysics/Newton-Raphson-Solver.git     # SSH
```
Building this program is done with these commands
```bash
mkdir build
cd build
cmake ..
make
```
The program can then be run with this commands
```bash
./NewtonRaphsonSolver
```

# Example output
```bash
Give me an initial guess for the root of the function x^2 - 2: 3
Give me a tolerance (default: 1e-8): 1e-8
Give me a max iteration number (default: 1000): 1000
The root of the function is 1.41421356
```
