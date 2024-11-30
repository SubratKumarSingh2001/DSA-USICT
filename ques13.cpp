#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Initialize the node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert the node in BST
Node* insertNode(Node* root, int value) {
    Node* newNode = createNode(value);

    if (root == NULL) {
        root = newNode;
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Searching for a node in the BST
bool searchNode(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    } 
    else {
        return searchNode(root->right, key);
    }
}

// Find the maximum node in the sub-tree
Node* findMax(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Deletion of a node in BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* maxNode = findMax(root->left);
            root->data = maxNode->data;
            root->left = deleteNode(root->left, maxNode->data);
        }
    }
    return root;
}

// Preorder traversal NLR
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder traversal LNR
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Postorder traversal LRN
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Print the BST
void printTree(Node* root, int space = 0, int indent = 4) {
    // Base case: if the node is NULL, return
    if (root == NULL) return;

    // Increase the distance between levels
    space += indent;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space count
    cout << endl;
    for (int i = indent; i < space; i++) {
        cout << " "; // Print spaces for indentation
    }
    cout << root->data << "\n"; // Print the current node's data

    // Process left child
    printTree(root->left, space);
}


int main() {
    Node* root = NULL;
    int choice, value, key;

    do {
        cout << "<-------------------x------------------>\n";
        cout << "Enter 1 to insert the node in BST.\n";
        cout << "Enter 2 to delete the node from BST.\n";
        cout << "Enter 3 to search an element in BST.\n";
        cout << "Enter 4 for Inorder Traversal.\n";
        cout << "Enter 5 for Preorder Traversal.\n";
        cout << "Enter 6 for Postorder Traversal.\n";
        cout << "Enter 7 to Exit.\n";
        
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert in BST: ";
                cin >> value;
                if (root == NULL) {
                    root = createNode(value);  // Only assign root on the first insertion
                } else {
                    insertNode(root, value);  // Subsequent insertions don’t change root
                }
                cout << "Updated BST:\n";
                printTree(root);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "BST after deletion:\n";
                printTree(root);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(root, value)) {
                    cout << "Value " << value << " found in the tree.\n";
                } else {
                    cout << "Value " << value << " not found in the tree.\n";
                }
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}


