#include <stdio.h>
#include <stdlib.h>

/*
 * Implementation of pow(x, n) - calculating x raised to the power n.
 * Includes O(log n) optimization and extreme edge case handling.
 */

double myPow(double x, int n) {
    // EDGE CASE 1: Anything to the power of 0 is 1.
    if (n == 0) return 1.0;
    
    // EDGE CASE 2: Base is 0. 0^0 is handled above. 0 to anything else is 0.
    // Also, if n is negative, it's division by zero, which we should prevent.
    if (x == 0) {
        if (n < 0) {
            printf("Error: Division by zero!\n");
            return 0.0; 
        }
        return 0.0;
    }

    // EDGE CASE 3: Integer overflow! 
    // The minimum 32-bit int is -2147483648. If we do `n = -n` to make it positive, 
    // it exceeds the maximum positive int (2147483647) and crashes the memory!
    // Solution: Cast n to a 64-bit long long integer first.
    long long power = n;

    // EDGE CASE 4: Negative powers mean fractions (e.g., 2^-3 = 1 / 2^3)
    if (power < 0) {
        power = -power;
        x = 1.0 / x;
    }

    double result = 1.0;
    
    // OPTIMIZATION: O(log n) approach (Binary Exponentiation).
    // Instead of multiplying 'x' 100 times, we square the base and halve the power.
    // This prevents Time Limit Exceeded (TLE) errors on massive numbers.
    while (power > 0) {
        if (power % 2 == 1) { // If power is odd
            result = result * x;
            power = power - 1;
        } else { // If power is even
            x = x * x;
            power = power / 2;
        }
    }

    return result;
}

int main() {
    // Testing the paranoid edge cases:
    printf("2.0 ^ 10 = %f\n", myPow(2.0, 10));             // Happy path
    printf("2.0 ^ -3 = %f\n", myPow(2.0, -3));             // Negative power (fraction)
    printf("0.0 ^ 5  = %f\n", myPow(0.0, 5));              // Zero base
    printf("2.0 ^ -2147483648 = %f\n", myPow(2.0, -2147483648)); // The ultimate overflow trap!
    
    return 0;
}