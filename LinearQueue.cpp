#include <iostream>
using namespace std;

#define SIZE 10

class Queue
{
    int a[SIZE];
    int rear;  // same as tail
    int front; // same as head

public:
    Queue() // Constructor to initialize the queue
    {
        rear = front = -1;
    }
    void enqueue(int x); // Function to add an element
    int dequeue();       // Function to remove and return the front element
    void display();      // Function to display the queue
};

// Function to add an element to the queue
void Queue::enqueue(int x)
{
    if (rear == SIZE - 1) // Check if the queue is full
    {
        cout << "The Queue is Full" << endl;
    }
    else
    {
        if (front == -1) // If the queue is empty, initialize front
        {
            front = 0;
        }
        rear++;           // Move the rear pointer forward
        a[rear] = x;     // Insert the element at the rear
        cout << x << " enqueued to the queue" << endl;
    }
}

// Function to remove an element from the queue
int Queue::dequeue()
{
    if (front == -1 || front > rear) // Check if the queue is empty
    {
        cout << "The Queue is Empty" << endl;
        return -1; // Indicate that the queue is empty
    }

    int dequeuedValue = a[front]; // Get the value at the front
    front++;                       // Move the front pointer to the next element

    // Reset front and rear if the queue becomes empty
    if (front > rear)
    {
        front = rear = -1; // Reset for next enqueue
    }

    return dequeuedValue; // Return the dequeued value
}

// Function to display the elements of the queue
void Queue::display()
{
    if (front == -1) // Check if the queue is empty
    {
        cout << "The Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) // Display from front to rear
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

// Main function to test the queue
int main()
{
    Queue q; // Create a Queue object

    q.enqueue(10); // Enqueue elements
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Display the queue

    cout << q.dequeue() << " dequeued from the queue" << endl; // Dequeue an element
    q.display(); // Display the queue again

    q.enqueue(40); // Enqueue another element
    q.display(); // Display the queue

    return 0;
}
