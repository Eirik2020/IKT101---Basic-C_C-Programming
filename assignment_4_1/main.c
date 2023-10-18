/*
Assignment 4_1 - Strings
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
Asks the user for a word and:
- Tells how many letters are in the word
- Tells if the word is a palindrome
- Prints the word reversed
 */

// Packages
#include <stdio.h> // For scanf and printf.
#include <stdbool.h> // For boolean operations.
#include <string.h> // For string manipulation.

// Definitions
#define STRING_LENGTH 30



// Functions
// Word letter count finder.
int letter_count(char str[]) {
    // Initializing count variable (stores the length of the string).
    int count;

    // Incrementing the count till the end of the string.
    for (count = 0; str[count] != '\0'; ++count);

    // Returning the character count of the string.
    return count;
}


// Check if word is a palindrome.
bool is_palindrome(char word[]) {
    // Find string length.
    int string_length = strlen(word);

    // Iterate from each end of the word and check if the letters match.
    int start = 0;
    int end = string_length -1;
    while (start < end) {
        if (word[start] != word[end]) {
            return false; // Not a palindrome.
        }
        start++;
        end--;
    }
    return true; // Is a palindrome.
}


// Reverse word.
void string_reverse(char word[]) {
    // Find string length.
    int string_length = strlen(word);

    // Reverse the word.
    char reversed[string_length];
    int j = 0;
    for (int i = string_length - 1; i >= 0; i--) {
        reversed[j++] = word[i];
    }
    reversed[j] = '\0';  // Null-terminate the reversed string.

    // Print reversed word.
    printf("The word reversed is '%s'\n", reversed);
}




// ####    Main Code    ####
int main() {
    // Create a string
    char word[STRING_LENGTH];

    // Ask the user for a string.
    printf("Enter a word: \n");
    scanf("%s", word);

    // Find the letter count of the word and print to terminal.
    int count = letter_count(word);
    printf("The word contains %i letters\n", count);

    // Check if the word is a palindrome.
    bool palindrome = is_palindrome(word);
    if (palindrome == true) {
        printf("The word is a palindrome\n");
    } else {
        printf("The word is not a palindrome\n");
    }

    // Reverse the word and print it.
    string_reverse((word));


    return 0;
}
