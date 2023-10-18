/* Assignment 4_4
 * Author: Eirik Kaldhol Strandman.
 * Version: V1.0
 * Description:
 * Prompts the user for a string and outputs the number of characters from the alphabet.
*/

// Packages
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definitions
#define STRING_LENGTH 200

// Functions
void countAlphabetchar(const char *str) {
    int alphabet[26] = {0}; // Initialize an array to store counts for each alphabet character

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]); // Convert the character to lowercase
        if (ch >= 'a' && ch <= 'z') {
            alphabet[ch - 'a']++; // Increment the count for the corresponding character
        }
    }

    printf("Character occurrences:\n");
    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        printf("'%c' : %d\n", ch, alphabet[i]);
    }
}


// Main code
int main() {
    // Initialize string.
    char str[STRING_LENGTH];

    // Prompt user for string.
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // Remove the newline character

    // Print number of characters from the alphabet.
    countAlphabetchar(str);


    return 0;
}