#include <iostream>
using namespace std;

class Stack
{
    int top;

public:
    int a[10]; // Stack with a maximum of 10 elements

    // Constructor to initialize top
    Stack()
    {
        top = -1;
    }

    void push(int x);
    int pop();
    bool isEmpty(); // Change to return a boolean
};

// Function to push an element onto the stack
void Stack::push(int x)
{
    if (top >= 9) // Max index is 9 for an array of size 10
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        a[++top] = x; // Increment top and then add the element
        cout << "Element Inserted: " << x << endl;
    }
}

// Function to pop an element from the stack
int Stack::pop()
{
    if (top < 0) // Check for underflow
    {
        cout << "Stack UnderFlow" << endl;
        return 0;
    }
    else
    {
        int d = a[top--]; // Remove the element and decrement top
        return d;
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty()
{
    return top < 0;
}
