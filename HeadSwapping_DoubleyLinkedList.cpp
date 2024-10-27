#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail; // Added tail pointer for easier management
    int LinkedListSize;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL; // Initialize tail to NULL
        LinkedListSize = 0;
    }

    void InsertNodeAtTail(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode; // Set tail to the new node
        } else {
            newNode->prev = tail;
            tail->next = newNode; // Link the old tail to the new node
            tail = newNode; // Update tail to the new node
        }
        LinkedListSize++;
    }

    void ChangeHead(int position) {
        // Check if the position is valid
        if (position < 1 || position > LinkedListSize) {
            cout << "Invalid position. Please enter a position between 1 and " << LinkedListSize << "." << endl;
            return;
        }

        Node *temp = head;  // Start from head
        // Traverse to the desired position (position - 1)
        for (int i = 1; i < position; i++) {
            temp = temp->next; // Move to the next node
        }

        // Swap the values of head and the node at the specified position
        int tempData = head->data;  // Store head data
        head->data = temp->data;     // Set head data to the node's data
        temp->data = tempData;       // Set the node's data to the stored head data

        cout << "Head changed to value: " << head->data << endl; // Show new head value
    }

    void Display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node *current = head;
        while (current != NULL) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;
    // Initial input: 3, 1, 4, 5
    list.InsertNodeAtTail(3);
    list.InsertNodeAtTail(1);
    list.InsertNodeAtTail(4);
    list.InsertNodeAtTail(5);

    cout << "Original List: ";
    list.Display();

    // Change head to the node at position 3 (which is 4)
    list.ChangeHead(3);
    cout << "List after changing head to position 3: ";
    list.Display(); // Expected Output: 4 1 3 5
    return 0;
}
