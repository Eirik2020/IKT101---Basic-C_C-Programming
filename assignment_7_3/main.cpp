/* Assignment 7.3
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that:
- Asks for the name of a student
- Asks for the name of a course and the grade the student got
- Does this until course name is "stop"
- Then asks for a new student until the name is "stop"
- Then prints out the grades gathered for each student
Using C++.
*/


// Packages
#include <iostream>
#include <string>
#include <vector>

// Classes
class Student {
public:
    std::string name;
    std::vector<std::pair<std::string, std::string>> grades; // Pair of course and grade
};


int main() { // Main Code
    // Create empty list of students
    std::vector<Student> students;

    // Loop
    while (true) {
        // Create temporary student class
        Student new_student;

        // Get user input for student name
        std::cout << "Enter student name (Enter stop, to stop): \n";
        std::getline(std::cin >> std::ws, new_student.name);

        // Check if the user wants to stop entering students
        if (new_student.name == "stop") {
            break;
        }

        // Gather grades for the current student
        while (true) {
            std::string new_student_course; // Declare the variable for course name
            std::string new_student_grade;  // Declare the variable for grade

            // Get user input for course Name
            std::cout << "Enter course code (Enter stop, to stop): \n";
            std::getline(std::cin >> std::ws, new_student_course);

            // Check if the user wants to stop entering grades for the current student
            if (new_student_course == "stop") {
                break;
            }

            // Get user input for grade
            std::cout << "Enter grade: \n";
            std::getline(std::cin >> std::ws, new_student_grade);

            // Add the course and grade to the current student's record
            new_student.grades.push_back({new_student_course, new_student_grade});
        }

        // Add the new student to the list
        students.push_back(new_student);
    }

    // Print out the grades gathered for each student in correct format
    for (const auto& student : students) {
        for (const auto& grade : student.grades) {
            std::cout << student.name << " - " << grade.first << " - " << grade.second << "\n";
        }
    }


    // Terminate program
    std::cout << "Shutting down...";
    return 0;
}
