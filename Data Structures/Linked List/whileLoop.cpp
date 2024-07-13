#include <iostream>

// Defining a class to represent every element of the linked list
class Node {
public:
    // Data will store in this node
    int data;
    // Reference of the next node
    Node* next;

    // Constructor for creating a node with given data
    Node(int data) {
        this->data = data;
        // there is no next node initially
        this->next = nullptr;
    }
};

// Main class to execute the code
int main() {
    // Define the head of the linked list
    Node* head = new Node(10);
    // Inserting some elements in the list
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Printing all elements of the singly linked list
    Node* ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
    //if (ptr == NULL) std::cout << "the ptr is null" << std::endl;

    Node* ptr1 = head;
    while (ptr1->next != nullptr) {
        ptr1 = ptr1->next;
        std::cout << ptr1->data << " ";
        //ptr1 = ptr1->next;
    }
    std::cout << std::endl;
    if (ptr1 == NULL) std::cout << "ptr1 is NULL" << std::endl;
    //ptr1 is the LAST ELEMENT of the linked list


    // Don't forget to free memory to avoid memory leaks
    ptr = head;
    while (ptr != nullptr) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    return 0;
}
//This code is contributed by Utkasrh
