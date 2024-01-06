/* Assignment 7.1
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that asks for two strings and:
- Tells if the strings are equal or not
- Tells if one string is a substring of the other
Using C++.
*/

// Packages
#include <iostream>
#include <string>


// Functions
void string_equal(const std::string& str1, const std::string& str2) {
    /*
    Takes in two strings and compares them, then reports to the user in the required task format.
    */
    // Compare strings.
    //int res = str1.compare(str2);

    // Print in required format.
    if (str1 == str2)
    {
        // Strings are equal if res = 0
        std::cout << "The strings are equal\n";
    } else
    {
        // Strings are equal if res 1 = 0
        std::cout << "The strings are not equal\n";
    }
}

void is_substring(const std::string& str1, const std::string& str2) {
    /*
    Checks if a string is a substring of the other.
    */
    // Use find() to detect if a string is a substring of the other, if string::npos is not returned, res equals true.
    bool res1 = str1.find(str2) != std::string::npos;
    bool res2 = str2.find(str1) != std::string::npos;

    // Print in required format.
    if (res1)
    {
        std::cout << "Last string is substring of first string\n";

    } else if (res2)
    {
        std::cout << "First string is substring of last string\n";
    } else
    {
        std::cout << "There are no substrings\n";
    }
}


int main() { // Main code:
    // Create empty strings
    std::string str1;
    std::string str2;

    // Ask user for the first string
    std::cout << "Please enter the first string: \n";
    std::getline(std::cin, str1); // Get user input.

    // Ask user for the second string
    std::cout << "Please enter the second string: \n";
    std::getline(std::cin, str2); // Get user input.

    // Check if strings are equal
    string_equal(str1, str2);

    // Check if a string is a substring of the other
    is_substring(str1, str2);

    // Terminate code
    std::cout << "Shutting down...";
    return 0;
}
