/*
 * Platform: HackerRank
 * Task: Playing With Characters (Introduction)
 * Link: https://www.hackerrank.com/challenges/playing-with-characters/problem
 * * Description:
 * Read a single character, a word, and a sentence from STDIN, then print them 
 * on separate lines.
 * * My Notes & Solution:
 * This task demonstrates how memory is allocated for a single char vs. an array of chars.
 * It also highlights a classic C pitfall: the input buffer. 
 * When reading the sentence with "%[^\n]%*c", I had to add a leading space in the 
 * scanf formatting string -> " %[^\n]%*c". This space forces scanf to discard any 
 * leftover newline characters (\n) from the previous inputs before reading the sentence.
 * Also, noted that arrays (like 'word') decay into pointers, so they don't need 
 * the '&' address-of operator in scanf.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // 1. Allocate memory on the stack
    char ch;
    char word[100];
    char sentence[100];
    
    // 2. Read the character (needs '&' because it's a single variable)
    scanf("%c", &ch);
    
    // 3. Read the word (no '&' needed, array name is already a pointer)
    scanf("%s", word);
    
    // 4. Read the sentence (The leading space clears the leftover '\n' from the buffer!)
    scanf(" %[^\n]%*c", sentence);
    
    // 5. Print everything on new lines
    printf("%c\n", ch);
    printf("%s\n", word);
    printf("%s\n", sentence);
    
    return 0;
}