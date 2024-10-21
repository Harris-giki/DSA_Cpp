#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
}; 

class DoublyLinkedList
{
private:
    Node *Head;

public:
    // Constructor
    DoublyLinkedList()
    {
        Head = NULL;
    }

    // Insert a node at the head of the list
    void insertAtHead(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = Head;
        newNode->prev = NULL;

        if (Head != NULL)
        {
            Head->prev = newNode;
        }
        Head = newNode; // Set the new node as head
    }

    // Insert a node at the tail of the list
    void insertAtTail(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;

        if (Head == NULL)
        {
            newNode->prev = NULL;
            Head = newNode;
        }
        else
        {
            Node *temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Display all nodes in the list
    void DisplayAllNode()
    {
        Node *temp = Head;
        int i = 1;
        while (temp != NULL)
        {
            cout << "THE VALUE OF THE NODE " << i << ": " << temp->value << endl;
            temp = temp->next;
            i++;
        }
    }

    // Delete a node by value (Key)
    void DeleteNode(int Key)
    {
        Node *currentNode = Head;

        // Traverse to find the node to delete
        while (currentNode != NULL && currentNode->value != Key)
        {
            currentNode = currentNode->next;
        }

        if (currentNode == NULL)
        {
            cout << "THE VALUE IS NOT FOUND IN THE LINKED LIST" << endl;
            return;
        }

        // If the node to delete is in the middle or at the tail
        if (currentNode->prev != NULL)
        {
            currentNode->prev->next = currentNode->next;
        }
        else
        {
            // The node is the head
            Head = currentNode->next;
        }

        // If the node to delete is not the tail
        if (currentNode->next != NULL)
        {
            currentNode->next->prev = currentNode->prev;
        }

        delete currentNode; // Free the memory
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.DisplayAllNode();
    dll.DeleteNode(20);
    dll.DisplayAllNode();

    return 0;
}
