#include <iostream>
#include <cmath>

using namespace std;

// Function to be integrated (example: f(x) = x^2)
double func(double x) {
    return x * x;  // Example function: f(x) = x^2
}

// Function to calculate the trapezoidal rule for a given interval [a, b] with n subintervals
double trapezoidalRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Romberg Integration Function without using vectors (using simple arrays)
double rombergIntegration(double (*f)(double), double a, double b, int maxIterations) {
    // Allocate a 2D array for Romberg's table
    double R[maxIterations][maxIterations];

    // First iteration: use trapezoidal rule for 1 subinterval (just the endpoints)
    R[0][0] = trapezoidalRule(f, a, b, 1);

    // Apply Romberg integration
    for (int i = 1; i < maxIterations; i++) {
        int n = pow(2, i);  // Number of subintervals for this iteration
        // Apply trapezoidal rule with 2^i subintervals
        R[i][0] = trapezoidalRule(f, a, b, n);

        // Extrapolation: use previous values to improve the estimate
        for (int j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    return R[maxIterations-1][maxIterations-1];  // The most accurate result after maxIterations
}

int main() {
    // Define the interval [a, b]
    double a = 0.0, b = 10.0;

    // Set the maximum number of iterations
    int maxIterations = 5;  // You can increase this for better precision

    // Calculate the integral using Romberg Integration
    double result = rombergIntegration(func, a, b, maxIterations);

    cout << "The integral of the function using Romberg Integration is approximately: " << result << endl;

    return 0;
}

