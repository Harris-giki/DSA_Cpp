#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
}; // Missing semicolon added

class SinglyCircularLinkedList
{
private:
    Node *Head;

public:
    // Constructor
    SinglyCircularLinkedList()
    {
        Head = NULL;
    }

    // Insert a node at the end
    void insertNodeatEnd(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;

        if (Head == NULL) // Correct comparison
        {
            Head = newNode;
            newNode->next = Head; // Circular linkage
        }
        else
        {
            Node *temp = Head;
            while (temp->next != Head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = Head; // Maintain circular link
        }
    }

    // Display all nodes
    void DisplayAllNodes()
    {
        if (Head == NULL)
        {
            cout << "THERE IS NO VALUE IN THE LINKED LIST" << endl;
            return;
        }

        Node *temp = Head;
        int i = 1;

        do
        {
            cout << "THE value of the Node " << i << " is: " << temp->value << endl;
            temp = temp->next;
            i++;
        } while (temp != Head); // Loop until back to Head (circular)

    }

    // Delete a specific node
    void DeleteSpecificNode(int value)
    {
        if (Head == NULL)
        {
            cout << "No value is present in the LinkedList" << endl;
            return;
        }

        Node *CurrentNode = Head;
        Node *previousNode = Head;

        // Case 1: If the node to delete is the head node
        if (Head->value == value)
        {
            if (Head->next == Head) // Only one node in the list
            {
                delete Head;
                Head = NULL;
            }
            else
            {
                Node *LastNode = Head;
                while (LastNode->next != Head) // Traverse to find the last node
                {
                    LastNode = LastNode->next;
                }
                Head = Head->next;
                LastNode->next = Head; // Maintain circular linkage
                delete CurrentNode;
            }
            return;
        }

        // Case 2: If the node is not the head
        CurrentNode = Head->next;
        previousNode = Head;

        while (CurrentNode != Head)
        {
            if (CurrentNode->value == value)
            {
                previousNode->next = CurrentNode->next;
                delete CurrentNode;
                return;
            }
            previousNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }

        // If the value is not found
        cout << "The value does not exist in the linked list" << endl;
    }
};

int main()
{
    SinglyCircularLinkedList scll;
    scll.insertNodeatEnd(10);
    scll.insertNodeatEnd(20);
    scll.insertNodeatEnd(30);
    scll.DisplayAllNodes();
    scll.DeleteSpecificNode(20);
    scll.DisplayAllNodes();
    return 0;
}
