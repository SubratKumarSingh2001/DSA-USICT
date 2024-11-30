#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Structure for the Stack
struct Stack {
    Node** arr; 
    int top;   
    int size; 
};

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (Node**)malloc(size * sizeof(Node*));
    return stack;
}
// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push a node onto the stack
void push(Stack* stack, Node* node) {
    if (stack->top < stack->size - 1) {
        stack->arr[++stack->top] = node;
    }
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return NULL;
}

// Function to perform inorder traversal using a stack
void inorderTraversal(Node* root) {
    Stack* stack = createStack(20); 
    Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left; 
        }

        current = pop(stack); 
        cout << current->data << " "; 
        current = current->right; 
    }
}

// Function to perform preorder traversal using a stack
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    Stack* stack = createStack(20); 
    push(stack, root);

    while (!isEmpty(stack)) {
        Node* current = pop(stack);
        cout << current->data << " "; 

        // Push right child first so that left child is processed first
        if (current->right != NULL) {
            push(stack, current->right);
        }
        if (current->left != NULL) {
            push(stack, current->left);
        }
    }
}

// Function to perform postorder traversal using a stack
void postorderTraversal(Node* root) {
    if (root == NULL) return;

    Stack* stack1 = createStack(20);
    Stack* stack2 = createStack(20);

    push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* current = pop(stack1);
        push(stack2, current); 

        // Push left and right children to the first stack
        if (current->left != NULL) {
            push(stack1, current->left);
        }
        if (current->right != NULL) {
            push(stack1, current->right);
        }
    }

    // Print nodes from the second stack
    while (!isEmpty(stack2)) {
        cout << pop(stack2)->data << " ";
    }
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to print the BST in a hierarchical format
void printTree(Node* root, int space = 0, int indent = 4) {
    if (root == NULL) return;

    // Increase the distance between levels
    space += indent;

    // Process right child first (to print it on the top)
    printTree(root->right, space);

    // Print current node after space count
    cout << endl;
    for (int i = indent; i < space; i++) {
        cout << " "; // Print spaces for indentation
    }
    cout << root->data; // Print the current node's data

    // Process left child
    printTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "<------------------- Menu ------------------>\n";
        cout << "1. Insert a node into the BST\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Print Tree\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted.\n";
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Tree Structure:\n";
                printTree(root);
                cout << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

