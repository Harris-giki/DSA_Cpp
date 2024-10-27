#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Function to push an element to the stack
void push(int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return -1; // Assuming -1 for error handling
    } else {
        int temp = top->data;
        top = top->next;
        return temp;
    }
}

// Function to display the stack elements
void display() {
    Node* ptr;
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        ptr = top;
        cout << "Stack elements are: ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

// Function to peek at the top element of the stack
int peek() {
    if (top != NULL) {
        return top->data;
    } else {
        cout << "No item found" << endl;
        return -1;
    }
}

// Function to insert an element into the stack in sorted order
void insert_sorted(int val) {
    if (top == NULL || val > top->data) {
        push(val);
    } else {
        int temp = pop();  // Pop the top and keep it aside
        insert_sorted(val); // Recursively insert the element
        push(temp); // Push the previous top back
    }
}

// Function to sort the stack using recursion
void sort_stack() {
    if (top != NULL) {
        int temp = pop();  // Pop the top element
        sort_stack();  // Sort the remaining stack
        insert_sorted(temp);  // Insert the popped element back in sorted order
    }
}

int main() {
    push(3);
    push(1);
    push(4);
    push(2);

    cout << "Original Stack: ";
    display();

    sort_stack();

    cout << "Sorted Stack: ";
    display();

    return 0;
}

