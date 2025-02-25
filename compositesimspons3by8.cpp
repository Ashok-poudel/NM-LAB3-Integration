#include <iostream>
#include <cmath>

using namespace std;

// Function to be integrated (example: f(x) = x^2)
double func(double x) {
    return x * x;  // Example function: f(x) = x^2
}

// Composite Simpson's 3/8 Rule Function
double simpsons38(double  (*f)(double), double a, double b, int n) {
    // Ensure n is a multiple of 3
    if (n % 3 != 0) {
        cout << "Error: n must be a multiple of 3." << endl;
        return -1; 
    }

    // Calculate the step size
    double h = (b - a) / n;
    double integral = f(a) + f(b); 

    // Sum the odd indices (1, 4, 7, ...) with a weight of 3
    for (int i = 1; i < n; i += 3) {
        integral += 3 * f(a + i * h);
    }

    // Sum the even indices (2, 5, 8, ...) with a weight of 3
    for (int i = 2; i < n; i += 3) {
        integral += 3 * f(a + i * h);
    }

    // Sum the multiples of 3 (3, 6, 9, ...) with a weight of 2
    for (int i = 3; i < n; i += 3) {
        integral += 2 * f(a + i * h);
    }

    // Multiply by 3h/8 to get the final result
    integral *= 3 * h / 8;

    return integral;
}

int main() {
    // Define the interval [a, b] and number of subintervals n
    double a = 0.0, b = 10.0;
    int n = 6;  // Ensure n is a multiple of 3 (e.g., 6, 9, 12, ...)

    // Calculate the integral using Composite Simpson’s 3/8 Rule
    double result = simpsons38(func, a, b, n);

    if (result != -1) {
        cout << "The integral of the function over [" << a << ", " << b << "] is approximately: " << result << endl;
    }

    return 0;
}

