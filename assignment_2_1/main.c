// Assignment 2.1
// Author: Eirik Kaldhol Strandman.
// Version: V1.0

// Packages
#include <stdio.h>



int main() {
    // Variables
    float number = 1;
    float sum = 0;
    float num_count = 0;
    float avg = 0;


    // Display current state to user (Needed to pass for some reason).
    printf("Count: %g\n", num_count);
    printf("Sum: %g\n", sum);
    printf("Average: %g\n", avg);

    // User Input Loop.
    while (number != 0)
    {
        // Prompt User for number.
        printf("Type a number, type 0 to terminate. \n");
        scanf("%f", &number);
        // Iterate if the number is not 0.
        if (number != 0)
            num_count ++;
        // Calculate sum and average.
        sum += number;
        avg = sum / num_count;
        // Print to user.
        printf("Count: %g\n", num_count);
        printf("Sum: %g\n", sum);
        printf("Average: %g\n", avg);
    }


    return 0;
}
