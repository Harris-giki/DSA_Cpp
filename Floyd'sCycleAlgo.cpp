#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SingleyLinkedList
{
public:
    Node *head = NULL;

    void insertNodeatTail(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL; // Ensure new node's next is NULL

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)  // Stop at the last node
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayAllNode()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)  // Condition for list without a cycle
    {
        slow = slow->next;          // Moves one step
        fast = fast->next->next;    // Moves two steps

        // If fast and slow meet, a loop exists
        if (fast == slow)
        {
            return true;
        }
    }
    return false;  // No loop detected
}

void makeCycle(Node *head, int position)
{
    Node *temp = head;     // Traversing to the end of the list
    Node *startNode = nullptr;  // Start of the cycle

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == position)    // Comparing the both
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode; // Last node points to startNode to form a cycle
}

void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // Detect cycle and find the meeting point
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Reset one pointer to head and find the cycle start
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Print the start and end of the cycle and break the loop
    cout << "Cycle detected at node with value: " << fast->next->data << endl;
    cout << "Loop removed from Node #" << slow->data << " -> Node #" << fast->next->data << endl;
    slow->next = NULL;  // Break the cycle
}

int main()
{
    SingleyLinkedList obj;
    obj.insertNodeatTail(10);
    obj.insertNodeatTail(20);
    obj.insertNodeatTail(30);
    obj.insertNodeatTail(40);
    obj.insertNodeatTail(50);

    cout << "Original List:" << endl;
    obj.displayAllNode();

    makeCycle(obj.head, 3);  // Creating a cycle at position 3

    // Checking if a cycle is detected
    if (detectCycle(obj.head)) {
        cout << "Cycle detected in the linked list." << endl;
        removeCycle(obj.head);
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    cout << "\nList after removing cycle:" << endl;
    obj.displayAllNode();

    return 0;
}
