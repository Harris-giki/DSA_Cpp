#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string address;
    string phoneNumber;

    // Constructor to initialize person information
    Person(string n, string a, string p) : name(n), address(a), phoneNumber(p) {}
};

struct Node {
    Person data;
    Node *next;

    // Node constructor to initialize with Person data
    Node(Person p) : data(p), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert a node in alphabetical order based on the name
    void insertInOrder(Person person) {
        Node *newNode = new Node(person);

        // If list is empty or new node should be placed at the head
        if (head == nullptr || head->data.name > person.name) {
            newNode->next = head;
            head = newNode;
        } else {
            // Find the appropriate position for insertion
            Node *current = head;
            while (current->next != nullptr && current->next->data.name < person.name) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Find a specific node by name
    void findPersonByName(string name) {
        Node *current = head;
        while (current != nullptr && current->data.name != name) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Person not found." << endl;
        } else {
            cout << "Person found:" << endl;
            cout << "Name: " << current->data.name << endl;
            cout << "Address: " << current->data.address << endl;
            cout << "Phone Number: " << current->data.phoneNumber << endl;
        }
    }

    // Display all persons in the address book
    void displayAllPersons() {
        Node *current = head;
        if (current == nullptr) {
            cout << "Address book is empty." << endl;
            return;
        }

        cout << "\nAddress Book Entries:" << endl;
        while (current != nullptr) {
            cout << "Name: " << current->data.name << endl;
            cout << "Address: " << current->data.address << endl;
            cout << "Phone Number: " << current->data.phoneNumber << endl;
            cout << "--------------------------" << endl;
            current = current->next;
        }
    }

    // Destructor to delete all nodes
    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList addressBook;
    int numPersons;

    // Ask the user for the number of persons to enter
    cout << "Enter the number of persons you want to add: ";
    cin >> numPersons;
    cin.ignore(); // To ignore the newline character after entering the number

    // Loop to add each person's details
    for (int i = 0; i < numPersons; ++i) {
        string name, address, phoneNumber;
        cout << "\nEnter details for person " << i + 1 << ":" << endl;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter phone number: ";
        getline(cin, phoneNumber);

        Person person(name, address, phoneNumber);
        addressBook.insertInOrder(person);
    }

    // Display all persons in the address book
    addressBook.displayAllPersons();

    // Finding a person by name
    string searchName;
    cout << "\nEnter name to search: ";
    getline(cin, searchName);
    addressBook.findPersonByName(searchName);

    return 0;
}
