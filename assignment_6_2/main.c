/* Assignment 6.2
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that asks for student information (name and age) until the name given is stop, then:
- Prints out how many students that are stored
- Prints out all the collected student information
- Prints out the name of the youngest student
- prints out the name of the oldest student
*/


// Packages
#include <stdio.h>  // For scanf(), printf() and fgets().
#include <string.h> // For string comparison.
#include <stdlib.h> // For memory allocation.

// Definitions
#define STRING_LENGTH 100


// Structures
typedef struct {
    char* name;
    int age;
} student_t;


// Functions
char* oldest(student_t* students, int size) {
    /*
    Finds the oldest student in the student_t struct.
    */
    // Initial guess for oldest student and largest number.
    int oldest_age = students[0].age;
    char* oldest_name = students[0].name;

    // Loop through ages and update if an older student is found.
    for (int i = 1; i < size; i++) {
        if (students[i].age > oldest_age) {
            oldest_age = students[i].age;
            oldest_name = students[i].name;
        }
    }

    return oldest_name;
}

char* youngest(student_t* students, int size) {
    /*
    Finds the youngest student in the student_t struct.
    */
    // Initial guess for youngest student and largest number.
    int youngest_age = students[0].age;
    char* youngest_name = students[0].name;

    // Loop through ages and update if a younger student is found.
    for (int i = 1; i < size; i++) {
        if (students[i].age < youngest_age) {
            youngest_age = students[i].age;
            youngest_name = students[i].name;
        }
    }

    return youngest_name;
}

void print_student_info(student_t* students, int mem_cap) {
    /*
    Prints out the student information in the student_t struct and the youngest and oldest student,
    found by using the functions oldest() and youngest().
    */
    // Print student count
    printf("Count: %d\n", mem_cap);

    // Print out student names and age
    for (int i = 0; i < mem_cap; i++) {
        printf("Name = %s, Age = %d\n", students[i].name, students[i].age);
    }

    // Print out the youngest and oldest student
    printf("Youngest: %s\n", youngest(students, mem_cap));
    printf("Oldest: %s\n", oldest(students, mem_cap));
}



int main() { // Main Program
    // ##  Set-up  ##
    // Set memory to zero initially.
    int mem_cap = 0;
    student_t* students = NULL;

    // Stop command
    char stop_str[STRING_LENGTH] = "stop";

    // Greet user
    printf("Good day sir!\n");


    // ##  Main program loop  ##
    while (1) {
        // Allocate memory for user input
        students = (student_t*)realloc(students, (mem_cap + 1) * sizeof(student_t));

        // Prompt user for input
        printf("Enter student name: \n");
        students[mem_cap].name = (char*)malloc(STRING_LENGTH);
        fgets(students[mem_cap].name, STRING_LENGTH, stdin);
        // Remove next line
        students[mem_cap].name[strcspn(students[mem_cap].name, "\n")] = '\0';

        // Check if the user entered stop
        if (strcmp(stop_str, students[mem_cap].name) == 0) {
        // User entered stop
            // Check if user entered data
            if (mem_cap == 0) {
                printf("No students were given\n");
            }
            // Stop program
            break;

        // User did not enter stop
        } else {
            // User entered a name.
            printf("Enter student age: \n");
            scanf("%d", &students[mem_cap].age);
            // Remove newline from input
            while (getchar() != '\n');
            // Remind user how to stop program
            printf("Enter 'stop' to end the program.\n");

            // Increase memory capacity
            mem_cap++;

            // Print student data
            print_student_info(students, mem_cap);
        }
    }

    // Free up memory for students
    for (int i = 0; i < mem_cap; i++) {
        free(students[i].name);
    }
    free(students);

    // Terminate program
    printf("Shutting down...\n");
    return 0;
}

