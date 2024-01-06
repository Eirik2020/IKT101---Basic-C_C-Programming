/* Assignment 5_2
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
The application prints a menu with the following choices:
- Read student information from file
- Write student information to file
- Exit
*/

// Packages
#include <stdio.h> // For fgets and printf.

// Definitions
#define STRING_LENGTH 100



// Functions
void write_student_info(char* filename, size_t str_size) {
    /*
     Prompts the user for:
     - Student ID
     - Name
     - Age
     And writes to file.
    */

    // Variables
    int int_data;
    char str_data[str_size];

    // # Open a file for writing and create if it does not exist. #
    FILE *file = fopen(filename, "w");

    // # Get User input and write to file #
    // Ask for student ID number and write to file.
    printf("What is your student ID number?\n");
    scanf("%d", &int_data);
    fprintf(file, "%i\n", int_data);

    // Ask for student name and write to file.
    printf("What is your full name?\n");
    getchar(); // Consume the newline character left by the previous Enter key press.
    fgets(str_data, sizeof(str_data), stdin);
    fprintf(file, "%s", str_data);

    // Ask for student age and write to file.
    printf("What is your age?\n");
    scanf("%d", &int_data);
    fprintf(file, "%i\n", int_data);

    // # Close file #
    fclose(file);
}



void read_student_info(char* filename, size_t str_size) {
    /*
     Reads student file and prints the information.
    */

    // Variables
    int id;
    int age;
    char name[STRING_LENGTH];

    // # Open a file for writing and create if it does not exist. #
    FILE *file = fopen(filename, "r");

    // Print user data
    // Read and print student ID.
    fscanf(file, "%d", &id);
    printf("Student id: %d\n", id);

    // Read and print student name.
    fscanf(file, " %[^\n]", name);
    printf("Name: %s\n", name);

    // Read and print student age.
    fscanf(file, "%d", &age);
    printf("Age: %d\n", age);

    // # Close file #
    fclose(file);
}


int main() { // Main Program
    // File name and location
    char file_name1[STRING_LENGTH] = "student_read.txt";
    char file_name2[STRING_LENGTH] = "student_write.txt";

    // Variables
    int choice; // Stores users choice as a number.
    int run = 1; // Enables program loop.

    // Loop program until user decides to exit.
        while (run != 0) {
            // Prompt user for input.
            printf("\n What do you want to do?\n");
            printf("Enter 1 to read student information from file.\n");
            printf("Enter 2 to write student information to file.\n");
            printf("Enter 3 to exit application.\n");
            scanf("%d", &choice);

            // Determine action based on user input.
            switch (choice) {
                case 1:
                    // Reads student file.
                    read_student_info(file_name1, STRING_LENGTH);
                    break;
                case 2:
                    // Writes to student file.
                    write_student_info(file_name2, STRING_LENGTH);
                    break;
                case 3:
                    // Exits loop.
                    printf("Exiting...\n");
                    run = 0;
                default:
                    // Tells user their input is invalid.
                    if (choice != 3) {
                        printf("Invalid Input\n");
                    }
            }
        }


        return 0; // Terminates program.
}