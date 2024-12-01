#include <iostream>
#include <queue> // Required for the queue
using namespace std;

// Define a Node structure
struct Node {
    int data;         // The value stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child

    // Constructor to initialize the node
    Node(int value) {
        data = value;         // Set the node's data
        left = NULL;          // Initially, no left child
        right = NULL;         // Initially, no right child
    }
};

// Function for Level Order Traversal with line breaks
void printLevelOrderTraversal(Node* root) {
    if (root == NULL) {
        // If the tree is empty, there's nothing to traverse
        return;
    }

    // A queue to manage nodes during traversal
    queue<Node*> q;

    // Start by pushing the root node and a NULL marker
    q.push(root);
    q.push(NULL);  // NULL marks the end of the current level

    while (!q.empty()) {
        // Get the front node in the queue
        Node* node = q.front();
        q.pop();  // Remove the node from the queue

        if (node != NULL) {
            // If the node is valid, print its data
            cout << node->data << " ";

            // Push its children into the queue
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        } else if (!q.empty()) {
            // If node is NULL, this means a level has ended
            cout << endl;      // Print a new line
            q.push(NULL);      // Add a NULL marker for the next level
        }
    }
}

int main() {
    // Creating a sample tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform level order traversal
    printLevelOrderTraversal(root);

    return 0;
}
