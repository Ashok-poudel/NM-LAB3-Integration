//Write a program to evaluate integration of a function using Gauss integration algorithm. 

#include <iostream>
#include <cmath>

using namespace std;

// Function to be integrated (example: f(x) = x^2)
double func(double x) {
    return x * x;  // Example function: f(x) = x^2
}

// Gaussian Quadrature Integration Function (2-point)
double gauss(double (*f)(double), double a, double b) {
    // Nodes for 2-point Gaussian Quadrature
    double x1 = -1.0 / sqrt(3); // First node
    double x2 = 1.0 / sqrt(3);  // Second node
    
    // Weights for 2-point Gaussian Quadrature
    double w1 = 1.0;
    double w2 = 1.0;

    // Transform the nodes to the interval [a, b]
    double transformed_x1 = 0.5 * (b - a) * x1 + 0.5 * (a + b);
    double transformed_x2 = 0.5 * (b - a) * x2 + 0.5 * (a + b);

    // Evaluate the function at the transformed nodes
    double integral = 0.5 * (b - a) * (w1 * f(transformed_x1) + w2 * f(transformed_x2));

    return integral;
}

int main() {
    // Define the interval [a, b]
    double a = 0.0, b = 10.0;

    // Calculate the integral using Gauss Quadrature
    double result = gauss(func, a, b);

    cout << "The integral of the function over [" << a << ", " << b << "] is approximately: " << result << endl;

    return 0;
}

