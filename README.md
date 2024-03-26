# Motivation
In maths, science and engineering, we often come to a situation, where we need to find the root of a function.
One of the most standard problems in quantum mechanics is to solve for the energies of an electron 
inside a one-dimensional finite square well. It can be shown that this scenario results in two
transcendental equation, whose roots can not be found with analytical methods. The Newton-Raphson root finding
algorithm exactly solves this problem, by first guessing the solution $x_0$ and then updating the guess
with the formula $x_n = x_n - \frac{f(x_n)}{f'(x_n)}$ iteratively until $|f(x_n)| < \epsilon$, where 
$\epsilon$ is a really small number ($\approx 10^{-8}$).  
