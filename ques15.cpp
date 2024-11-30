#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

// Function to get height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Utility function to create a new node
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;  // New node is initially at height 1
    return node;
}

// Update height of a node
void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}

// Get balance factor of a node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    // Return new root
    return y;
}

// Insert a node in the AVL tree
Node* insert(Node* node, int key) {
    // 1. Perform normal BST insert
    if (!node)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // No duplicate keys allowed

    // 2. Update height of this ancestor node
    updateHeight(node);

    // 3. Get balance factor to check if node is unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to print in-order traversal of the AVL tree
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Free memory allocated for the AVL tree
void freeTree(Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    Node* root = nullptr;
    int choice, key;

    do {
        cout << "\nAVL Tree Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display in-order traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                root = insert(root, key);
                cout << "Inserted " << key << " into the AVL tree.\n";
                break;

            case 2:
                cout << "In-order traversal of the AVL tree: ";
                inOrder(root);
                cout << endl;
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    // Free the allocated memory
    freeTree(root);

    return 0;
}
