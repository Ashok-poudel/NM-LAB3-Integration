#include <iostream>
#include <cmath>

using namespace std;

// Function to be integrated (example: f(x, y) = x^2 + y^2)
double func(double x, double y) {
    return x * x + y * y;  // Example: f(x, y) = x^2 + y^2
}

// Trapezoidal Rule for Double Integration
double trapezoidalDoubleIntegral(double (*f)(double, double), double a, double b, double c, double d, int n, int m) {
    double hx = (b - a) / n;  // Step size for x
    double hy = (d - c) / m;  // Step size for y
    double integral = 0.0;

    // Apply trapezoidal rule to the double integral
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            double x = a + i * hx;
            double y = c + j * hy;
            // Apply trapezoidal rule for both x and y
            double weight = 1.0;
            if (i == 0 || i == n) weight /= 2;
            if (j == 0 || j == m) weight /= 2;
            integral += weight * f(x, y);
        }
    }
    integral *= hx * hy;

    return integral;
}

int main() {
    // Define the bounds for x and y
    double a = 0.0, b = 10.0;
    double c = 0.0, d = 10.0;

    // Set the number of intervals for x and y (higher values give more accuracy)
    int n = 10;  // Number of intervals in x-direction
    int m = 10;  // Number of intervals in y-direction

    // Calculate the double integral using the trapezoidal rule
    double result = trapezoidalDoubleIntegral(func, a, b, c, d, n, m);

    cout << "The double integral of the function is approximately: " << result << endl;

    return 0;
}

