#include <stdio.h>

/**
 * Task: Sum and Difference of Two Numbers (HackerRank)
 * * My Goal: Practice low-level data handling in C, specifically 
 * understanding how integers and floating-point numbers are 
 * represented and processed in memory.
 * * Connection to my Data Engineering path: 
 * In Python, I take memory for granted. Here, I'm learning to 
 * manage precision (using %.1f) and types (int vs float) manually,
 * which is essential for optimizing ETL pipelines and data structures.
 */

int main() 
{
    // I am declaring two integers (4 bytes each) and two floats (4 bytes each).
    int int1, int2;
    float float1, float2;
    
    // Using scanf to read input. I use the '&' operator to pass the 
    // memory address of my variables so scanf knows exactly where to store the data.
    if (scanf("%d %d", &int1, &int2) != 2) return 1;
    if (scanf("%f %f", &float1, &float2) != 2) return 1;
    
    // Calculating and printing the results for integers.
    // %d is my placeholder for decimal integers.
    printf("%d %d\n", int1 + int2, int1 - int2);
    
    // For floats, I use %.1f to round the output to one decimal place.
    // This is a great example of controlling data precision at the output stage.
    printf("%.1f %.1f\n", float1 + float2, float1 - float2);
    
    return 0;
}