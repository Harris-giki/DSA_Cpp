#include <iostream>
using namespace std;

// Structure to define each node in the binary search tree (BST)
struct node
{
    int data;  // Data part of the node
    node *left;  // Pointer to the left child
    node *right;  // Pointer to the right child
    
    // Constructor to initialize a node with a value
    node(int value)
    {
        data = value;
        left = right = NULL;  // Initially, both left and right children are NULL
    }
};

// Insertion mechanism for BST
node *insert(node *root, int value)
{
    // If the tree is empty, create a new node and return it as the root
    if (root == NULL)
    {
        return new node(value);
    }
    else if (value < root->data)  // If value is smaller, go to the left subtree
    {
        root->left = insert(root->left, value);
    }
    else  // If value is greater, go to the right subtree
    {
        root->right = insert(root->right, value);
    }
    return root;  // Return the root of the tree
}

// Searching for the kth smallest value in the BST using inorder traversal
void inorderTraversal(node *root, int &k, int &result)
{
    // If the node is NULL, return
    if (root == NULL)
    {
        return;
    }
    
    // Traverse the left subtree
    inorderTraversal(root->left, k, result);

    // Decrease k for each node visited (in-order)
    k = k - 1;
    
    // When k becomes 0, we have found the kth smallest element
    if (k == 0)
    {
        result = root->data;  // Store the result
        return;  // Stop further traversal
    }
    
    // Traverse the right subtree
    inorderTraversal(root->right, k, result);
}

// Level-order traversal (BFS)
void levelOrder(node *root)
{
    if (root == NULL)  // If the tree is empty
    {
        cout << "The tree is empty" << endl;
        return;
    }

    node *queue[100];  // A queue to help with level-order traversal
    int front = 0, rear = 0;

    queue[rear++] = root;  // Enqueue the root node
    
    // Process the queue
    while (front < rear)
    {
        node *current = queue[front++];  // Dequeue the front node
        cout << current->data << " ";  // Print the data of the current node
        
        // Enqueue left child if exists
        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        
        // Enqueue right child if exists
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}

// In-order traversal to display the tree
void printTree(node *root)
{
    if (root == NULL)  // If the node is NULL, do nothing
    {
        return;
    }
    
    // Traverse the left subtree
    printTree(root->left);
    
    // Print the current node's data
    cout << root->data << endl;
    
    // Traverse the right subtree
    printTree(root->right);
}

// Find the minimum value node in the BST (leftmost node)
node *findMinimum(node *root)
{
    while (root->left != NULL)  // Keep moving left to find the minimum node
    {
        root = root->left;
    }
    return root;
}

// Delete a node with a given value in the BST
node *deleteNode(node *root, int value)
{
    if (root == NULL)  // If the tree is empty, nothing to delete
    {
        return root;
    }

    // If the value to be deleted is smaller, go to the left subtree
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    // If the value to be deleted is greater, go to the right subtree
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else  // If we found the node to be deleted
    {
        if (root->left == NULL)  // If the node has no left child
        {
            node *temp = root->right;  // Get the right child
            delete root;  // Delete the current node
            return temp;  // Return the right child
        }
        else if (root->right == NULL)  // If the node has no right child
        {
            node *temp = root->left;  // Get the left child
            delete root;  // Delete the current node
            return temp;  // Return the left child
        }

        // If the node has two children, find the minimum node in the right subtree
        node *temp = findMinimum(root->right);
        
        // Copy the inorder successor's data to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;  // Return the modified root node
}

// Search for a value in the BST
bool searchBST(node *root, int target)
{
    if (root == NULL)  // If the tree is empty
    {
        cout << "There is no value in the tree" << endl;
        return false;
    }

    // If the target is found
    if (root->data == target)
    {
        cout << "Value found at root" << endl;
        return true;
    }
    else if (target < root->data)  // If the target is smaller, search in the left subtree
    {
        return searchBST(root->left, target);
    }
    else  // If the target is larger, search in the right subtree
    {
        return searchBST(root->right, target);
    }
}

int main()
{
    node *root = NULL;  // Initially, the tree is empty

    // Insert values into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the tree using inorder traversal
    cout << "Inorder traversal: ";
    printTree(root);
    cout << endl;

    // Perform level order traversal
    cout << "Level order traversal: ";
    levelOrder(root);
    cout << endl;

    // Search for a value in the BST
    int target = 40;
    if (searchBST(root, target))
    {
        cout << "Found " << target << endl;
    }
    else
    {
        cout << "Did not find " << target << endl;
    }

    // Find the kth smallest value (e.g., 3rd smallest)
    int k = 3;
    int result = -1;
    inorderTraversal(root, k, result);
    cout << "The " << k << "th smallest value is: " << result << endl;

    // Delete a node with value 20 and print the tree again
    root = deleteNode(root, 20);
    cout << "Tree after deleting 20: ";
    printTree(root);
    cout << endl;

    return 0;
}
