#include <iostream>
#include <algorithm> // For std::max

using namespace std;

// Structure representing a node in the AVL tree
struct node {
    int data;  // Value of the node
    node *left; // Left child of the node
    node *right; // Right child of the node
    int height; // Height of the node in the AVL tree

    // Constructor to initialize a node
    node(int value) {
        data = value;
        left = right = NULL;
        height = 1; // Initially, the height of a new node is 1
    }
};

// Function to calculate the height of a node
int height(node *n) {
    if (n == NULL) {
        return 0; // Height of NULL node is 0
    }
    return n->height;
}

// Function to update the height of a node
void updateHeight(node *n) {
    if (n != NULL) {
        n->height = 1 + std::max(height(n->left), height(n->right)); // Height is 1 + max of left and right subtree heights
    }
}

// Function to calculate the balance factor of a node
int balanceFactor(node *n) {
    if (n == NULL) {
        return 0; // Balance factor of NULL node is 0
    }
    return height(n->left) - height(n->right); // Balance factor = height of left subtree - height of right subtree
}

// Right rotation for balancing the tree (used when left subtree is heavier)
node *rightRotate(node *y) {
    node *x = y->left;
    node *t2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = t2;

    // Update heights after rotation
    updateHeight(y);
    updateHeight(x);

    return x; // New root after rotation
}

// Left rotation for balancing the tree (used when right subtree is heavier)
node *leftRotate(node *x) {
    node *y = x->right;
    node *t2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = t2;

    // Update heights after rotation
    updateHeight(x);
    updateHeight(y);

    return y; // New root after rotation
}

// Left-Right rotation (used when left subtree is heavier, but right child of left is heavier)
node *leftRightRotate(node *n) {
    n->left = leftRotate(n->left); // Perform left rotation first
    return rightRotate(n); // Then perform right rotation
}

// Right-Left rotation (used when right subtree is heavier, but left child of right is heavier)
node *rightLeftRotate(node *n) {
    n->right = rightRotate(n->right); // Perform right rotation first
    return leftRotate(n); // Then perform left rotation
}

// Insert a new key in the AVL tree and balance it
node *insert(node *n, int key) {
    // Step 1: Perform the normal BST insert
    if (n == NULL) {
        return new node(key); // If the tree is empty, create a new node
    }

    if (key < n->data) {
        n->left = insert(n->left, key); // Insert in the left subtree
    } else if (key > n->data) {
        n->right = insert(n->right, key); // Insert in the right subtree
    } else {
        return n; // Duplicate keys are not allowed in AVL tree
    }

    // Step 2: Update the height of the ancestor node
    updateHeight(n);

    // Step 3: Get the balance factor of the node and check if it became unbalanced
    int balance = balanceFactor(n);

    // If the node becomes unbalanced, there are four cases to handle:

    // Left Left Case
    if (balance > 1 && key < n->left->data) {
        return rightRotate(n);
    }

    // Right Right Case
    if (balance < -1 && key > n->right->data) {
        return leftRotate(n);
    }

    // Left Right Case
    if (balance > 1 && key > n->left->data) {
        return leftRightRotate(n);
    }

    // Right Left Case
    if (balance < -1 && key < n->right->data) {
        return rightLeftRotate(n);
    }

    // Return the (unchanged) node pointer
    return n;
}

// Function to print details of the node (height, balance factor)
void printNodeInfo(node *n) {
    if (n == NULL) {
        cout << "Node is NULL" << endl;
        return;
    }
    int balance = balanceFactor(n);
    cout << "Node " << n->data << ": Height = " << n->height
         << ", Balance Factor = " << balance << endl;
}

// Function to analyze node and balance factor to determine the required rotation
void analyzeAndBalance(node *n, int key) {
    if (n == NULL) {
        return;
    }
    // Calculate the balance factor for the node
    int balance = balanceFactor(n);
    cout << "Analyzing Node " << n->data << ": Balance Factor = " << balance << endl;

    // Depending on the balance factor, determine the type of rotation required
    if (balance > 1) {
        cout << "Node " << n->data << " is left heavy" << endl;
        if (key < n->left->data) {
            cout << "Left Left Case: Performing Right Rotation" << endl;
            rightRotate(n); // Perform right rotation for left-left case
        } else {
            cout << "Left Right Case: Performing Left-Right Rotation" << endl;
            leftRightRotate(n); // Perform left-right rotation for left-right case
        }
    } else if (balance < -1) {
        cout << "Node " << n->data << " is right heavy" << endl;
        if (key > n->right->data) {
            cout << "Right Right Case: Performing Left Rotation" << endl;
            leftRotate(n); // Perform left rotation for right-right case
        } else {
            cout << "Right Left Case: Performing Right-Left Rotation" << endl;
            rightLeftRotate(n); // Perform right-left rotation for right-left case
        }
    }
}

// Function to delete a node (to be implemented as needed)
void deleteNode(node *n, int key) {
    // Deletion implementation (not yet provided in this code)
    cout << "Delete function is not yet implemented" << endl;
}

int main() {
    node *root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);

    // Print the tree's node details (height and balance factor)
    printNodeInfo(root);
    printNodeInfo(root->left);
    printNodeInfo(root->right);

    // Additional node insertions to test the balancing
    root = insert(root, 25);
    root = insert(root, 5);
    printNodeInfo(root);

    return 0;
}
