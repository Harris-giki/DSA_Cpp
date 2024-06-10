#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class myhashmaps {
private:
    static const int size = 1000;
    // main formation of the hashmap is here in this private region of the class;
    Node* table[size];

    int hashmap_function(int key) {
        return key % size;
    }

public:
    myhashmaps() {
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    void put(int key, int value) {
        int hash = hashmap_function(key);
        Node *prev = nullptr;
        Node *entry = table[hash];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) { // if the key does not already exist
            entry = new Node(key, value);

            if (prev == nullptr) { // if it's the first node, add the entry at the head of the hash
                table[hash] = entry;
            } else { // else add to the next to the previous node
                prev->next = entry;
            }
        } else { // else, the key is found and we simply replace the value of the node with that key
            entry->value = value;
        }
    }

    void remove(int key) // now making a function to remove a node from the hashmaps
    {
        int hash = hashmap_function(key);
        Node *prev = nullptr;
        Node *entry = table[hash];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) { // if the node is not found we do nothing
            return;
        } else {
            if (prev == nullptr) { // if the node is found in the head
                table[hash] = entry->next; // simply change the head to have the next value
            } else { // condition if the node is found in any other place except the head
                prev->next = entry->next;
            }
            delete entry;
        }
    }

    int get(int key) {
        int hash = hashmap_function(key);
        Node *entry = table[hash];

        while (entry != nullptr && entry->key != key) {
            entry = entry->next;
        }

        if (entry == nullptr) { // nothing to be found now
            return -1;
        } else {
            return entry->value;
        }
    }
};

int main() // the code ahead is quite simple and self explanatory
{
    char choice2;
    myhashmaps obj;
    do {
        int key;
        int value;
        cout << "WELCOME TO THE HASH MAP MODEL SYSTEM" << endl;
        cout << "YOU ARE PROVIDED WITH THE FOLLOWING METHODS" << endl;
        cout << endl;
        cout << "1. ADD VALUES WITH SPECIFIC KEYS INTO THE HASHMAP TABLE" << endl;
        cout << "2. REMOVE SPECIFIC VALUES FROM THE HASHMAP TABLE" << endl;
        cout << "3. GET CERTAIN VALUE THAT IS STORED IN YOUR HASHMAP TABLE" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "ENTER THE KEY: ";
            cin >> key;
            cout << "ENTER THE VALUE CORRESPONDING TO YOUR KEY: ";
            cin >> value;
            obj.put(key, value);
            break;

        case 2:
            cout << "ENTER THE KEY FOR REMOVAL: ";
            cin >> key;
            obj.remove(key);
            break;

        case 3:
            cout << "ENTER THE KEY WHOSE VALUE YOU WANT TO EXTRACT: ";
            cin >> key;
            value = obj.get(key);
            if (value == -1) {
                cout << "Key not found" << endl;
            } else {
                cout << "Value: " << value << endl;
            }
            break;

        default:
            cout << "THE CHOICE ENTERED IS INCORRECT" << endl;
        }

        cout << "PRESS Y IF YOU WANT TO RERUN THE PROGRAM: ";
        cin >> choice2;
        cout << endl;

    } while (choice2 == 'y' || choice2 == 'Y');

    return 0;
}
