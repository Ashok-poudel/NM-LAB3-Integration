#include <iostream>
#include <cmath>

using namespace std;

// Function to be integrated (example: f(x) = x^2)
double func(double x) {
    return x * x;  // Example function: f(x) = x^2
}

// Composite Simpson's 1/3 Rule Function
double simpsons13(double (*f)(double), double a, double b, int n) {
    // Ensure n is even
    if (n % 2 != 0) {
        cout << "Error: n must be an even number." << endl;
        return -1;  // Return error code
    }

    // Calculate the step size
    double h = (b - a) / n;
    double integral = f(a) + f(b); // Add the endpoints f(x_0) and f(x_n)

    // Sum the odd indices (1, 3, 5, ...) with a weight of 4
    for (int i = 1; i < n; i += 2) {
        integral += 4 * f(a + i * h);
    }

    // Sum the even indices (2, 4, 6, ...) with a weight of 2
    for (int i = 2; i < n; i += 2) {
        integral += 2 * f(a + i * h);
    }

    // Multiply by h/3 to get the final result
    integral *= h / 3;

    return integral;
}

int main() {
    // Define the interval [a, b] and number of subintervals n
    double a = 0.0, b = 10.0;
    int n = 6;  // Ensure n is even (e.g., 6, 8, 10, ...)

    // Calculate the integral using Composite Simpson’s 1/3 Rule
    double result = simpsons13(func, a, b, n);

    if (result != -1) {
        cout << "The integral of the function over [" << a << ", " << b << "] is approximately: " << result << endl;
    }

    return 0;
}

