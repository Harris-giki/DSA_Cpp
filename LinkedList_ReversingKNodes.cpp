#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class linkedlist {
private:
    Node *head;

public:
    linkedlist() {
        head = NULL;
    }

    // Function to insert at the tail of the linked list
    void insertatTail(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to reverse k nodes in the linked list
    void reverseKNodes(int k) {
        if (head == NULL || k <= 1) return; // No need to reverse if list is empty or k is invalid

        // Step 1: Store the linked list values in an array
        Node *temp = head;
        int size = 0;

        // Calculate size of the linked list
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        // Create an array to store values
        int *arr = new int[size];
        temp = head;

        // Fill the array with linked list values
        for (int i = 0; i < size; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }

        // Step 2: Reverse every k elements in the array
        for (int i = 0; i < size; i += k) {
            int left = i;
            int right = min(i + k - 1, size - 1); // Handle the last group if less than k

            // Reverse the elements from left to right
            while (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }

        // Step 3: Reconstruct the linked list from the modified array
        temp = head; // Reset temp to head
        for (int i = 0; i < size; i++) {
            temp->data = arr[i]; // Update linked list values
            temp = temp->next;
        }

        delete[] arr; // Free the allocated memory for the array
    }

    // Function to print the linked list
    void printList() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to delete all nodes
    ~linkedlist() {
        Node *ptrPrevious;
        while (head != NULL) {
            ptrPrevious = head;
            head = head->next;
            delete ptrPrevious;
        }
    }
};

int main() {
    linkedlist list;
    list.insertatTail(10);
    list.insertatTail(20);
    list.insertatTail(30);
    list.insertatTail(40);
    list.insertatTail(50);
    
    cout << "Original list: ";
    list.printList();

    int k = 5;
    list.reverseKNodes(k);

    cout << "Reversed list in groups of " << k << ": ";
    list.printList();

    return 0;
}
