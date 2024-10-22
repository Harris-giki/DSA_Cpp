#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class CircularDoublyLinkedList
{
private:
    Node *Head;

public:
    // Constructor to initialize the list
    CircularDoublyLinkedList()
    {
        Head = NULL;
    }

    // Insert a node at the head (beginning) of the circular list
    void insertAtHead(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;

        if (Head == NULL)
        {
            // First node, points to itself
            newNode->next = newNode;
            newNode->prev = newNode;
            Head = newNode;
        }
        else
        {
            Node *last = Head->prev; // Last node in the circular list

            newNode->next = Head;
            newNode->prev = last;
            Head->prev = newNode;
            last->next = newNode;

            Head = newNode; // Set the new node as the new head
        }
    }

    // Insert a node at the tail (end) of the circular list
    void insertAtTail(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;

        if (Head == NULL)
        {
            // First node, points to itself
            newNode->next = newNode;
            newNode->prev = newNode;
            Head = newNode;
        }
        else
        {
            Node *last = Head->prev; // Last node in the circular list

            newNode->next = Head;
            newNode->prev = last;
            last->next = newNode;
            Head->prev = newNode;
        }
    }

    // Display all nodes in the circular list
    void DisplayAllNodes()
    {
        if (Head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *temp = Head;
        int i = 1;

        // Traverse through the circular list
        do
        {
            cout << "Node " << i << ": " << temp->value << endl;
            temp = temp->next;
            i++;
        } while (temp != Head); // Stop when we return to the head
    }

    // Delete a node by value
    void DeleteNode(int Key)
    {
        if (Head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *currentNode = Head;

        // Traverse to find the node to delete
        do
        {
            if (currentNode->value == Key)
            {
                if (currentNode->next == currentNode && currentNode->prev == currentNode)
                {
                    // Only one node in the list
                    delete currentNode;
                    Head = NULL;
                }
                else
                {
                    Node *prevNode = currentNode->prev;
                    Node *nextNode = currentNode->next;

                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;

                    if (currentNode == Head)
                    {
                        Head = nextNode; // If head is being deleted, update head
                    }

                    delete currentNode;
                }
                return;
            }
            currentNode = currentNode->next;
        } while (currentNode != Head); // Stop when we return to the head

        cout << "The value is not found in the linked list." << endl;
    }
};

int main()
{
    CircularDoublyLinkedList cdll;
    cdll.insertAtHead(10);  // Inserting at the head
    cdll.insertAtTail(20);  // Inserting at the tail
    cdll.insertAtTail(30);  // Inserting another at the tail
    cdll.DisplayAllNodes(); // Display all nodes

    cdll.DeleteNode(20);    // Delete a node with value 20
    cdll.DisplayAllNodes(); // Display all nodes after deletion

    return 0;
}
