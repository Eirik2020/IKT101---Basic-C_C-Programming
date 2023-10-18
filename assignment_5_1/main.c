/* Assignment 5_1
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that asks the user for the following student information (in this order):
- Student id
  Example: 3872187
- Name
  Example: John Doe
- Age
  Example: 21
Then prints the information back to the user.
*/


// Packages
#include <stdio.h> // For fgets and printf.

// Definitions
#define STRING_LENGTH 100

// Structures
typedef struct
{
    int student_id;
    char name[STRING_LENGTH];
    int age;
} student_t;

int main() {
    // Generate student structure.
    student_t student1;

    // Prompt user for information.
    printf("Good day sir!\n");
    printf("What is your student ID number?\n");
    scanf("%d", &student1.student_id);

    printf("What is your full name?\n");
    getchar(); // Consume the newline character left by the previous Enter key press.
    fgets(student1.name, sizeof(student1.name), stdin);

    printf("What is your age?\n");
    scanf("%d", &student1.age);

    // Print user data
    printf("Student id: %i\n", student1.student_id);
    printf("Name: %s", student1.name);
    printf("Age: %i\n", student1.age);

    return 0; // Terminate Program.
}

