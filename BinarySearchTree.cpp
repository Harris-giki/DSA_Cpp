#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int value) {
        data = value;
        right = left = NULL;
    }
};

// Insert a new node in the BST
Node *insert(Node *root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Find the minimum value node in the tree
Node *findMin(Node *root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
Node *deleteNode(Node *root, int value) {
    if (root == NULL) {
        return root;
    }

    // Find the node to delete
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);
        root->data = temp->data;  // Copy the inorder successor's data
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }

    return root;
}

// In-order traversal to print the tree
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the original tree: ";
    inorder(root);
    cout << endl;

    // Delete node 30
    root = deleteNode(root, 30);
    cout << "Inorder traversal after deleting 30: ";
    inorder(root);
    cout << endl;

    // Delete node 70
    root = deleteNode(root, 70);
    cout << "Inorder traversal after deleting 70: ";
    inorder(root);
    cout << endl;

    return 0;
}
