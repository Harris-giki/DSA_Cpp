#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail; // Added tail pointer for easier management
    int LinkedListSize;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL; // Initialize tail to NULL
        LinkedListSize = 0;
    }

    void InsertNodeAtTail(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode; // Set tail to the new node
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode; // Link the old tail to the new node
            tail = newNode; // Update tail to the new node
        }
        LinkedListSize++;
    }

    Node* FindNode(int value)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return NULL; // Return NULL if the node is not found
    }

    void SwapNodes(int a, int b)
    {
        if (a == b)
            return; // No need to swap identical nodes

        Node *nodeA = FindNode(a);
        Node *nodeB = FindNode(b);

        if (!nodeA || !nodeB)
        {
            cout << "One or both nodes not found, swap operation failed." << endl;
            return;
        }

        // If nodeA is adjacent to nodeB
        if (nodeA->next == nodeB) // nodeA comes before nodeB
        {
            // Adjust pointers for adjacent nodes
            nodeA->next = nodeB->next;
            nodeB->prev = nodeA->prev;

            if (nodeB->next)
                nodeB->next->prev = nodeA; // Link the next node to nodeA
            if (nodeA->prev)
                nodeA->prev->next = nodeB; // Link the previous node to nodeB
            else
                head = nodeB; // nodeA was head, now nodeB is head

            nodeB->next = nodeA; // Now nodeB points to nodeA
            nodeA->prev = nodeB; // Now nodeA points back to nodeB

            // Update tail if necessary
            if (tail == nodeA)
                tail = nodeB; // If nodeA was the tail, update tail
        }
        else if (nodeB->next == nodeA) // nodeB comes before nodeA
        {
            // Adjust pointers for adjacent nodes
            nodeB->next = nodeA->next;
            nodeA->prev = nodeB->prev;

            if (nodeA->next)
                nodeA->next->prev = nodeB; // Link the next node to nodeB
            if (nodeB->prev)
                nodeB->prev->next = nodeA; // Link the previous node to nodeA
            else
                head = nodeA; // nodeB was head, now nodeA is head

            nodeA->next = nodeB; // Now nodeA points to nodeB
            nodeB->prev = nodeA; // Now nodeB points back to nodeA

            // Update tail if necessary
            if (tail == nodeB)
                tail = nodeA; // If nodeB was the tail, update tail
        }
        else // Nodes are not adjacent
        {
            // Store pointers to next and prev nodes
            Node *tempA_prev = nodeA->prev;
            Node *tempA_next = nodeA->next;
            Node *tempB_prev = nodeB->prev;
            Node *tempB_next = nodeB->next;

            // Unlink nodes from their current positions
            if (tempA_prev)
                tempA_prev->next = nodeB;
            else
                head = nodeB; // nodeA was head, now nodeB is head

            if (tempB_prev)
                tempB_prev->next = nodeA;
            else
                head = nodeA; // nodeB was head, now nodeA is head

            if (tempA_next)
                tempA_next->prev = nodeB;
            else
                tail = nodeB; // nodeA was tail, now nodeB is tail

            if (tempB_next)
                tempB_next->prev = nodeA;
            else
                tail = nodeA; // nodeB was tail, now nodeA is tail

            // Swap next and prev pointers
            nodeA->prev = tempB_prev;
            nodeA->next = tempB_next;
            nodeB->prev = tempA_prev;
            nodeB->next = tempA_next;

            // Link the new positions
            if (tempB_prev) tempB_prev->next = nodeA;
            if (tempA_prev) tempA_prev->next = nodeB;
            if (tempB_next) tempB_next->prev = nodeA;
            if (tempA_next) tempA_next->prev = nodeB;
        }
    }

    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.InsertNodeAtTail(3);
    list.InsertNodeAtTail(1);
    list.InsertNodeAtTail(8);
    list.InsertNodeAtTail(5);
    list.InsertNodeAtTail(4);
    list.InsertNodeAtTail(2);
    list.InsertNodeAtTail(9);
    list.InsertNodeAtTail(6);
    list.InsertNodeAtTail(7);

    cout << "Original List: ";
    list.Display();

    list.SwapNodes(4, 5); // Swap nodes with values 4 and 5
    cout << "List after swapping 4 and 5: ";
    list.Display();

    list.SwapNodes(1, 3); // Swap nodes with values 1 and 3
    cout << "List after swapping 1 and 3: ";
    list.Display();

    list.SwapNodes(2, 6); // Swap nodes with values 2 and 6
    cout << "List after swapping 2 and 6: ";
    list.Display();

    list.SwapNodes(8, 9); // Swap nodes with values 8 and 9 (non-adjacent)
    cout << "List after swapping 8 and 9: ";
    list.Display();

    list.SwapNodes(1, 1); // Try swapping identical nodes
    cout << "List after attempting to swap 1 with 1: ";
    list.Display();

    return 0;
}
