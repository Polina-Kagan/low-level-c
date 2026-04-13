#include <stdio.h>

/*
 * Task: Functions in C
 * Goal: Create a function to find the maximum of four integers.
 * * Connection to Data Engineering:
 * Functions in C help us encapsulate logic for heavy computations. 
 * While Python's max() is convenient, understanding how to implement 
 * such logic at the register level helps in writing optimized 
 * UDFs (User Defined Functions) for databases.
 */

int max_of_four(int a, int b, int c, int d) {
    int max = a; // Assume 'a' is the largest initially

    if (b > max) {
        max = b; // 'b' is bigger, update max
    }
    if (c > max) {
        max = c; // 'c' is bigger, update max
    }
    if (d > max) {
        max = d; // 'd' is bigger, update max
    }

    return max; // Return the final winner to the main program
}

int main() {
    int a, b, c, d;
    // Reading 4 integers from standard input
    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) return 1;
    
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}