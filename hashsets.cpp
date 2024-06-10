#include <iostream>
using namespace std;

struct Node // component of a linked list
{
    int key;
    Node *next;
    Node(int K) : key(K), next(nullptr) {}
};

class hashsets1
{
private:
    static const int size1 = 1000; // determining the size of the array
    Node *container[size1]; // this is the hashtable i.e an array of linked lists

    int hashfunction(int key) // Added key parameter here
    {
        return key % size1;
    }

public:
    hashsets1()
    {
        for (int i = 0; i < size1; i++)
        {
            container[i] = nullptr;
        }
    }

    void add(int key)
    {
        int hash = hashfunction(key);
        Node *current = container[hash];

        while (current != nullptr)
        {
            if (current->key == key)
                return;

            current = current->next;
        }

        Node *newNode = new Node(key);
        newNode->next = container[hash];
        container[hash] = newNode;
    }

    void remove(int key)
    {
        int hash = hashfunction(key);
        Node *current = container[hash];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr) //indicating that the loop ran and the key is found at the head node
                {
                    container[hash] = current->next;
                }
                else //indicating that the node with the specific key found is not in the head/elsewhere
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    bool contain(int key) //the code to check if the user-defined key exists or not is quite simple and self-explanatory
    {
        int hash = hashfunction(key);
        Node *current = container[hash];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                return true;
            }
            current = current->next;
        }
        return false; // return false only after traversing the entire list
    }
};
