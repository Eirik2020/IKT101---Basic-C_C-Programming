/* Assignment 4_2
 * Author: Eirik Kaldhol Strandman.
 * Version: V1.0
 * Description:
 * Prompts the user for a word, and prints it in upper and lowercase,
 * as well as splitting the word with a hyphen and printing it.
*/

// Packages
#include <stdio.h> // For scanf and printf.
#include <string.h> // For string manipulation.
#include <ctype.h> // For converting to upper/lowercase.

// Definitions
#define STRING_LENGTH 200


// Converts word to lower case.
void string_lower(char *word) {
    /* Description:
     * Takes in a string and converts all character to lowercase.
     */


    // Make a buffer.
    char *result = strdup(word);

    // Converter each character to lowercase.
    for (int i = 0; result[i]; i++) {
        result[i] = tolower(result[i]);
    }

    // Remove the newline character if it exists
    if (result[strlen(result) - 1] == '\n') {
        result[strlen(result) - 1] = '\0';
    }

    // Print the lowercase word.
    printf("The word in lowercase is '%s'\n", result);
}


// Converts word to upper case.
void string_upper(char *word) {
    /* Description:
     * Takes in a string and converts all character to uppercase.
     */


    // Make a buffer.
    char *result = strdup(word);

    // Converter each character to lowercase.
    for (int i = 0; result[i]; i++) {
        result[i] = toupper(result[i]);
    }

    // Remove the newline character if it exists
    if (result[strlen(result) - 1] == '\n') {
        result[strlen(result) - 1] = '\0';
    }

    // Print the lowercase word.
    printf("The word in uppercase is '%s'\n", result);
}


// Splits string in two and adds hyphen.
void split_and_print_w_hyphen(char* str) {
    /* Description:
     * Takes in a string, splits it in two (at int length / 2) and adds " - " hyphen in the split,
     * and prints in this format:
     * "The word split in two is '(word start) - (word_end)'"
     */


    // ##  Split the string in two  ##
    // Find string length.
    int len = strlen(str);

    // Initialize character arrays.
    char str_start[50] = ""; // Initialize with an empty string
    char str_end[50] = "";   // Initialize with an empty string

    // Loop through original string.
    int j = 0;
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i < (len / 2)) {
            str_start[j] = str[i];
            j++;
        } else {
            str_end[k] = str[i];
            k++;
        }
    }
    // Terminate str_end at k-1 to remove \n.
    str_end[k-1] = '\0';


    // ##  Combine strings with new formatting  ##
    // Create formatting.
    char* ans_start = "The word split in two is '";
    char* hyphen = " - ";
    char* ans_end = "'";

    // Calculate the total length of the concatenated string
    int totalLength = strlen(ans_start) + strlen(str_start) + strlen(hyphen) + strlen(str_end) + strlen(ans_end);

    // Create a character array to store the concatenated string
    char answer[totalLength + 1]; // +1 for the null terminator '\0'

    // Combine strings.
    strcpy(answer, ans_start);
    strcat(answer, str_start);
    strcat(answer, hyphen);
    strcat(answer, str_end);
    strcat(answer, ans_end);


    // ##  Print strings  ##
    printf("%s\n", answer);


    }


// ####    Main Code    ####
int main() {
    // Create a string
    char word[STRING_LENGTH];

    // Ask the user for a string.
    printf("Enter a word:\n");
    fgets(word, STRING_LENGTH, stdin);

    // Print in upper and lower case.
    string_upper(word);
    string_lower(word);
    split_and_print_w_hyphen(word);


    return 0;
}