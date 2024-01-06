/* Assignment 6.1
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that:
- Asks the user how many integers the user will type in
- Allocates memory for the number of integers that were specified by the user
- Reads in all the integers
- Prints the integers in the order they were entered
- Prints the integers in ascending order (sorted)
*/


// Packages
#include <stdio.h> // For printf() and scanf().
#include <stdlib.h> // For malloc() and free().


// Functions
void bubbleSort(int arr[], int n) {
    /*
    Takes in an array and its length.
    Sorts in ascending order.
    */
    int temp;
    int swapped;

    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap arr[i] and arr[i+1]
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}


// Main Program
int main() {
    // Prompt user to input the amount of numbers they want to input.
    int size;
    printf("How many numbers do you want to enter? \n");
    scanf("%d", &size);


    // Check if user wants to input zero numbers or if they input a negative size.
    if (size > 0){
        /* If the user wants to input an amount of numbers greater than zero. */

        // Allocate memory
        int *numbers = (int *)malloc(size * sizeof(int));

        // Prompt user to input numbers.
        printf("Please enter %d numbers:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
        }

        // Formatting and printing
        printf("##  User numbers  ## \n");

        // Print the size of the array
        printf("Count: %d\n", size);

        // Print the user's numbers.
        printf("Numbers: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }

        // Print sorted numbers
        bubbleSort(numbers, size);
        printf("\nSorted: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }

        // Free up memory
        free(numbers); // Don't forget to free the allocated memory when done.
        numbers = NULL;
    } else {
        /* If the user attempts an invalid input, like a negative or zero amount of numbers. */
        printf("No numbers were given");
    }


    return 0; // Terminate Program
}