/* ###  Assignment 3 - arrays and functions  ###
 * Author: Eirik Kaldhol Strandman.
 * Version: V1.0
*/


// Packages
#include <stdbool.h>
#include <stdio.h>


// Definitions
#define ARRAY_SIZE 10


// Functions
// Calculates the sum of the array.
int sum(int numbers1[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum = sum + numbers1[i];
    }
    return sum;
}

// Calculates the minimum value of the array.
int minimum(int numbers[], int count)
{
    int min = numbers[0];
    for (int i = 0; i < count; i++)
    {
        if (min > numbers[i])
            min = numbers[i];
    }
    return min;
}

// Calculates the maximum value of the array.
int maximum(int numbers[], int count)
{
    int max = numbers[0];
    for (int i = 0; i < count; i++)
    {
        if (max < numbers[i])
            max = numbers[i];
    }
    return max;
}

// Calculates the maximum value of the array.
float average(float sum, float count)
{
    float avg = sum / count;
    return avg;
}

// Swaps around two values.
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Uses bubblesort to sort the array.
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

// Calculates the median value of the array.
float median(int numbers[], int count)
{
    float median_value;
    if ( count % 2 == 0)
        median_value = (numbers[(count-1)/2] + numbers[(count-1)/2 + 1])/2.0 ;
    else
        median_value = numbers[count/2 + 1];
    return median_value;
}



// Main Program
int main()
{
    // Create array and prompt user for numbers.
    printf("Input 10 whole numbers: \n");
    int numbers1[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%i", &numbers1[i]);
    }

    // Find minimum value of array.
    int minimum_numbers1 = minimum(numbers1, ARRAY_SIZE);
    printf("Minimum: %i\n", minimum_numbers1);

    // Find maximum value of array.
    int maximum_numbers1 = maximum(numbers1, ARRAY_SIZE);
    printf("Maximum: %i\n", maximum_numbers1);

    // Find sum of array.
    int sum_numbers1 = sum(numbers1, ARRAY_SIZE);
    printf("Sum: %i\n", sum_numbers1);

    // Find average of array.
    float average_numbers1 = average(sum_numbers1, ARRAY_SIZE);
    printf("Average: %g\n", average_numbers1);

    // Sort Array
    bubbleSort(numbers1, ARRAY_SIZE);
    printf("Sorted: ");
    for(int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", numbers1[i]);
    printf("\n");

    // Find median of array.
    float median_numbers1 = median(numbers1, ARRAY_SIZE);
    printf("Median: %g\n", median_numbers1);



    return 0;
}
