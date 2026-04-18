#include <stdio.h>

/*
 * Task: In-place string reversal using the two-pointer technique.
 * * Notes:
 * I implemented this function without relying on <string.h> to deepen my understanding
 * of pointer arithmetic and memory addressing. 
 * I am using two pointers ('start' and 'end') to swap characters until they meet.
 * This approach has O(n) time complexity and O(1) space complexity.
 */

void reverse_string(char *s) {
    if (s == NULL || *s == '\0') {
        return;
    }

    char *start = s;
    char *end = s;

    // Moving 'end' pointer to the last valid character of the string
    while (*end != '\0') {
        end++;
    }
    end--;

    // Swapping characters using a temporary variable
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    // Note: Using an array creates a mutable buffer on the stack.
    // If I used a string literal (char *s = "hello"), it would reside 
    // in read-only memory, causing a Segmentation Fault during swap.
    char my_string[] = "Molly";
    
    reverse_string(my_string);
    printf("%s\n", my_string);

    return 0;
}