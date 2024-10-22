#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int a[SIZE];
    int rear; // same as tail
    int front; // same as head

public:
    Queue() {
        rear = front = -1;
    }
    
    void enqueue(int x);
    int dequeue();
    void display();
    bool isEmpty(); // Helper function to check if queue is empty
    int size(); // Function to get current size of the queue
};

void Queue::enqueue(int x) {
    if (rear == SIZE - 1) {
        cout << "The Queue is Full" << endl;
    } else {
        if (front == -1) {
            front = 0; // Set front to 0 if it's the first element
        }
        a[++rear] = x; // Add element to the rear
    }
}

int Queue::dequeue() {
    if (front == -1) {
        cout << "The Queue is Empty" << endl;
        return -1; // Queue is empty
    } else {
        int value = a[front++];
        if (front > rear) { // Reset when queue becomes empty
            front = rear = -1;
        }
        return value;
    }
}

bool Queue::isEmpty() {
    return (front == -1);
}

int Queue::size() {
    return (rear - front + 1);
}

void Queue::display() {
    if (isEmpty()) {
        cout << "The Queue is Empty" << endl;
    } else {
        for (int i = front; i <= rear; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void Interleave(Queue& Q1) {
    if (Q1.isEmpty()) {
        cout << "The Queue is Empty" << endl;
        return;
    }

    int middle_point = Q1.size() / 2;
    int array1[SIZE], array2[SIZE];

    // Dequeue elements into the two arrays
    for (int i = 0; i < middle_point; i++) {
        array1[i] = Q1.dequeue();
    }
    for (int i = 0; i < middle_point; i++) {
        array2[i] = Q1.dequeue();
    }

    // Interleave elements back into the original queue
    for (int i = 0; i < middle_point; i++) {
        Q1.enqueue(array1[i]);
        Q1.enqueue(array2[i]);
    }
}

int main() {
    Queue Q1;

    // Example input: 1 2 3 4 5 6 7 8
    for (int i = 1; i <= 8; i++) {
        Q1.enqueue(i);
    }

    cout << "Original Queue: ";
    Q1.display();

    Interleave(Q1);

    cout << "Interleaved Queue: ";
    Q1.display();

    return 0;
}
