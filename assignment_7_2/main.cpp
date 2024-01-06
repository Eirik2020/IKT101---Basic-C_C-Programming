/* Assignment 7.2
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that asks for numbers until 0 is given as input and:
- Prints out the average
- Prints out the median
- Prints out the numbers sorted, in descending order
Using C++.
*/


// Packages
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

// Functions
std::list<int> get_numbers(std::list<int>& numbers) {
    // Initialize variable
    int num;

    // Prompt user
    std::cout << "Enter number(s), enter 0 to exit:\n";

    // Loop until user enters zero.
    while (true)
    {
        // Get user input
        std::cin >> num;

        if (num != 0){ // User input is not a zero, add number to list.
            numbers.push_back(num);

        } else { // User input is zero, terminate loop.
            break;
        }
    }
    return numbers;
}

void find_average(const std::list<int>& numbers) {
    // Find sum
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // Find number count
    double count = numbers.size();

    // Find average
    double avg = sum / count;

    // Print in correct format
    std::cout << "Average : " << avg << "\n";
}

void find_median(std::list<int>& numbers) {
    double median;

    // Sort the list in descending order
    numbers.sort(std::greater<int>());

    // Find the size of the list
    size_t size = numbers.size();

    // Find the middle iterator
    auto middle_it = std::next(numbers.begin(), size / 2);

    // Check if list size is even or odd
    if (size % 2 == 0) { // Is even
        auto middle_it_prev = std::prev(middle_it);
        median = (*middle_it + *middle_it_prev) / 2.0;
    } else { // Is odd
        median = *middle_it;
    }
    // Print in correct format
    std::cout << "Median : " << median << "\n";
}

void sort_list(std::list<int>& numbers) {
    // Sort the list in descending order
    numbers.sort(std::greater<double>());

    // Print the sorted list in correct format
    std::cout << "Descending : ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}


int main() { // Main code:
    // Initialize list
    std::list<int> numbers;

    // Run functions
    get_numbers(numbers);
    find_average(numbers);
    find_median(numbers);
    sort_list(numbers);

    // Terminate Program
    std::cout << "Shutting down...\n";
    return 0;
}