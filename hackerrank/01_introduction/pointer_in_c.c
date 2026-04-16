#include <stdio.h>
#include <stdlib.h>

/**
 * Task: Pointers in C (HackerRank)
 * * My Goal: To understand how to manipulate data directly in memory 
 * using pointers. This task involves updating variable values 
 * by their addresses rather than returning new values.
 * * Connection to my Data Engineering path: 
 * In Data Engineering, efficiency is everything. When working with 
 * massive datasets (e.g., in C-based engines like DuckDB or Apache Arrow), 
 * modifying data "in-place" using pointers prevents unnecessary copying. 
 * This saves RAM and significantly speeds up ETL transformations.
 */

void update(int *a, int *b) {
    // I am dereferencing the pointers to extract the actual values 
    // from the memory addresses provided.
    int val_a = *a;
    int val_b = *b;

    // Here, I perform "in-place" modification:
    // 1. I overwrite the memory at address 'a' with the sum.
    *a = val_a + val_b;
    
    // 2. I overwrite the memory at address 'b' with the absolute difference.
    // I use the abs() function from stdlib.h to ensure the result is non-negative.
    *b = abs(val_a - val_b);
}

int main() {
    int a, b;
    // Defining pointers and assigning them the addresses of a and b.
    int *pa = &a, *pb = &b;
    
    // Reading the input values directly into the memory locations of a and b.
    if (scanf("%d %d", &a, &b) != 2) return 1;

    // Passing the pointers (addresses) to the update function.
    update(pa, pb);

    // Printing the modified values. Because I used pointers, 
    // the changes made inside the 'update' function persist here!
    printf("%d\n%d", a, b);

    return 0;
}