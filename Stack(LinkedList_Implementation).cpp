#include <iostream>
using namespace std;

// Define the structure of a node
struct Node
{
    int data;      // Data part
    Node* next;    // Pointer to the next node
};

// Define the stack class using linked list
class Stack
{
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack()
    {
        top = NULL; // Initially, the stack is empty
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        Node* newNode = new Node; // Allocate memory for the new node
        newNode->data = x;        // Set the value for the new node
        newNode->next = top;      // Point the new node to the current top
        top = newNode;            // Update the top to the new node
        cout << "Element Inserted: " << x << endl;
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (top == NULL) // Check for underflow (empty stack)
        {
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        else
        {
            Node* temp = top;   // Temporary pointer to hold the top node
            int poppedValue = top->data; // Get the value of the top node
            top = top->next;    // Move top to the next node
            delete temp;        // Free memory of the old top node
            return poppedValue; // Return the popped value
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Function to display the elements of the stack
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test the stack
int main()
{
    Stack s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Display stack elements
    s.display();

    // Pop an element from the stack
    cout << "Popped Element: " << s.pop() << endl;

    // Display stack elements after pop
    s.display();

    // Check if the stack is empty
    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
