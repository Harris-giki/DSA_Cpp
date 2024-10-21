#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedlist
{
private:
    Node *head;
    
public:
    // Constructor
    linkedlist()
    {
        head = NULL;
    }

    // Insert a node at the head
    void insertatHead(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at the tail
    void insertatTail(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Find a specific node by value
    void FindSpecificNode(int value)
    {
        Node *ptrCurrent = head;
        while (ptrCurrent != NULL && ptrCurrent->data != value)
        {
            ptrCurrent = ptrCurrent->next;
        }

        if (ptrCurrent == NULL)
        {
            cout << "Value is not found" << endl;
        }
        else
        {
            cout << "The value is found in the linked list" << endl;
        }
    }

    // Delete a node by value
    void deleteNode(int value)
    {
        Node *ptrCurrent = head;
        Node *ptrPrevious = NULL;

        while (ptrCurrent != NULL && ptrCurrent->data != value)
        {
            ptrPrevious = ptrCurrent;
            ptrCurrent = ptrCurrent->next;
        }

        if (ptrCurrent == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }

        if (ptrCurrent == head)
        {
            head = head->next;
        }
        else
        {
            ptrPrevious->next = ptrCurrent->next;
        }
        delete ptrCurrent;
    }

    // Destructor to delete all nodes
    ~linkedlist()
    {
        Node *ptrPrevious;
        while (head != NULL)
        {
            ptrPrevious = head;
            head = head->next;
            delete ptrPrevious;
        }
    }
};

int main()
{
    // Example usage
    linkedlist list;
    list.insertatHead(10);
    list.insertatTail(20);
    list.FindSpecificNode(10);
    list.deleteNode(10);
    return 0;
}
