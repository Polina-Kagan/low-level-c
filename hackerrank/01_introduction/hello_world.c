/*
 * Platform: HackerRank
 * Task: "Hello World!" in C (Introduction)
 * Link: https://www.hackerrank.com/challenges/hello-world-c/problem
 * * Description:
 * Read a string from standard input and print "Hello, World!" followed 
 * by the input string on the next line.
 * * My Notes & Solution:
 * In this basic task, I explored how C handles string inputs compared to high-level languages.
 * I explicitly allocated 100 bytes of stack memory for the character array.
 * To read the entire line (including spaces), I used the regex-like format specifier 
 * "%[^\n]%*c" in scanf. This tells the program to read everything until it hits a newline 
 * character, and then discard the newline itself from the input buffer.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // I am allocating memory on the stack for a string of up to 100 characters.
    char s[100];
    
    // Reading the entire line of input until the Enter key (\n) is pressed.
    scanf("%[^\n]%*c", &s);
    
    // Printing the mandatory greeting.
    printf("Hello, World!\n");
    
    // Printing the string I stored in memory.
    printf("%s\n", s);
    
    return 0;
}