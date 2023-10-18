/* Assignment 4_3
 * Author: Eirik Kaldhol Strandman.
 * Version: V1.0
 * Description:
 * Prompts the user for two strings and tells the user if they are equal, or a substring of the other.
*/

// Packages
#include <stdio.h> // For fget and printf.
#include <string.h> // For string manipulation.

// Definitions
#define STRING_LENGTH 200


// Main code
int main() {
    // Create a string
    char str1[STRING_LENGTH];
    char str2[STRING_LENGTH];

    // Ask the user for twp strings.
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1) - 1] = '\0'; // Remove the newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2) - 1] = '\0'; // Remove the newline character

    // Check if strings are equal.
    if (strcmp(str1, str2) == 0) {
        printf("The words are equal\n");
    } else {
        printf("The words are not equal\n");
    }

    // Check if str1 is a substring of str2 or vice versa.
    if (strstr(str1, str2) != NULL) {
        printf("Word 2 is a substring of word 1\n", str2, str1);
    } else if (strstr(str2, str1) != NULL) {
        printf("Word 1 is a substring of word 2\n", str1, str2);
    } else {
        printf("No substrings found\n");
    }

    return 0;
}
