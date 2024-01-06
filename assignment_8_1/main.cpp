/* Assignment 8.1
Author: Eirik Kaldhol Strandman.
Version: V1.0

Description:
An application that creates a linked-list, with a menu that the user can use to:
 - Add a number to the list.
 - Show number at the index given.
 - Remove number for the index given.
 - Print the numbers of the list and the amount of numbers.
 The program will loop until the user inputs exit (option 5).
Using C++ C14.
*/

// Packages
#include <iostream>


// Classes
class node{
    /*
    Creates a node in a linked list.
     */
public:
    int data; // Integer value in the node.
    node* next; // Pointer to the next node in the chain.

    // Constructor
    node(int value) : data(value), next(nullptr) {}
}; // End of class.

class list{
    /*
    A linked-list class.
     */
private:
    node* head; // Pointer to the head of the linked list.

public:
    // Constructor
    list() : head(nullptr) {} // Set head pointer to Null initially.

    // Destructor to free memory
    ~list() {
        // Loop until head equals the null terminator
        while (head) {
            node* temp = head; // Set temporary variable equal to pointer.
            head = head->next; // Move head pointer to the next node in the list.
            delete temp; // Deallocate memory from temporary variable.
        }
    }

    // Functions
    void push_back(const int value){
        /*
        Creates a new node to store the given integer value, and puts it at the back of your linked list.
        */
        // Creates new node with the given value
        node* node_new = new node(value); // Set pointer address to new_node.
        node* last_node = head; // Set pointer of last node to the head.

        // If the list is empty, the new node becomes the head
        if (head == nullptr) {
            head = node_new;
        } else {
            // Traverse the list to find the last node
            while (last_node->next != nullptr) {
                last_node = last_node->next;
            }

            // Insert the new node at the end of the list
            last_node->next = node_new;
        }
    } // End of function.

    size_t size(){
        /*
        Gets the number of items within the linked-list.
        */
        // Loop until current pointer hits the null pointer at the end of the list.
        size_t count = 0; // Set counter to zero.
        node* current = head; // Set temporary pointer to head of the list.
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count; // Return current count.
    } // End of function.

    int& at(size_t index){
        /*
        Gets the reference to the item at the given index within the linked-list.
        */
        // Set temporary pointer to the head of the linked-list.
        node* current = head;

        // Loop Until "i" equals the index.
        for (size_t i = 0; i < index; i++) {
            // Check if "current" is a null pointer
            if (current != nullptr) { // If index is not a null pointer.
                current = current->next;
            } else { // If index is out of range
                throw std::out_of_range("Index out of range"); // Error handling
            }
        }
        // Checks if "current" is a null pointer after loop finishes.
        if (current != nullptr) { // If index is not a null pointer.
            return current->data; // Return current value reference.
        } else { // If index is out of range
            throw std::out_of_range("Index out of range"); // Error handling
        }
    }

    void remove(size_t index){
        /*
         Removes item at the given index in the linked-list
         If the list is empty, index is out of range or the node empty, it does nothing.
        */
        // ## Pre-checks before deleting node ##
        // Check if the list is empty or the index is out of range.
        if (head == nullptr || index < 0) { // Check if head is a null pointer or index is zero.
            // If true, do nothing.
            return;
        }

        // Check if the index is 0 and the head is not null, make head next as head and delete previous head
        if (index == 0) { // If true:
            // Set pointer to current head.
            node* nodeToDelete = head;

            // Update the head of the linked-list to the next node.
            head = head->next;

            // Delete node that was the previous head of the linked-list.
            delete nodeToDelete;
            return;
        }

        // ## If no issues were encountered, proceed ##
        // Traverse until the position before the node to be deleted is found.
        node* temp = head; // Set temporary node to head.
        // Loop Until "i" equals the index.
        for(size_t i = 0; i < index-1; i++) {
            // Check if "current" is a null pointer
            if(temp != nullptr) { // If index is not a null pointer.
                temp = temp->next;

            } else { // If the given node is already null, do nothing
                return;
            }
        }

        // Check if the node to be deleted and next node is not a null pointer.
        if(temp != nullptr && temp->next != nullptr) {
            node* nodeToDelete = temp->next; // Set pointer to node that will be deleted.

            // Update the next pointer, so it skips the node to be deleted, disconnecting it.
            temp->next = temp->next->next;

            // Free memory.
            delete nodeToDelete;
        } // If the given node is already null, do nothing
    } // End of function.

    void display() {
        /*
        Displays all the values in the linked list.
        */
        // Loop until current pointer hits the null pointer at the end of the list.
        node* current = head; // Set temporary pointer to head of the list.
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    } // End of function.
}; // End of Class


// Main Code
int main() {
    // Create a linked list
    list linked_list;

    // Variables
    int menu; // User's menu input
    int index; // Index in the linked list.
    int value; // Value provided by the user.

    // Loop program until user wants to exit.
    do {
        // Prompt user for input with menu
        std::cout << "\nMenu\n";
        std::cout << "1. Add integer\n";
        std::cout << "2. Show integer at index\n";
        std::cout << "3. Remove integer at index\n";
        std::cout << "4. Print information\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your menu: ";

        // Get user input for the menu.
        std::cin >> menu;

        // Determine action based on user input.
        switch (menu) {
            case 1: // User wants to input number.
                // Prompt user for a number and add to linked list  using .push_back.
                std::cout << "Enter a number: ";
                std::cin >> value;
                linked_list.push_back(value);
                break;

            case 2: // User wants to see number at index.
                // Prompt user for an index and look up using .at
                std::cout << "Enter an index: ";
                std::cin >> index;
                std::cout << "Integer at index " << index << ": " << linked_list.at(index) << std::endl;
                break;

            case 3: // User wants to remove number at index.
                // Prompt user for an index and remove using .remove
                std::cout << "Enter an index: ";
                std::cin >> index;
                linked_list.remove(index);
                break;

            case 4: // User wants to display all the numbers in the list.
                // Display numbers using .display and amount with .size.
                if (linked_list.size() == 0) {
                    std::cout << "List contains no integers" << std::endl;
                } else {
                    std::cout << "List contains " << linked_list.size() << " integers: ";
                    linked_list.display();
                }
                break;

            case 5: // User wants to exit program.
                std::cout << "Exiting...";
                break;

            default: // User failed to give a valid input.
                std::cout << "ERROR! Invalid input!\n";
        }
    } while (menu != 5); // If user inputs 5, exit loop.


    // Terminate Program
    return 0;
}