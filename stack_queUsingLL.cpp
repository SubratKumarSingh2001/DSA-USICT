#include <iostream>
using namespace std;

/*-------------------------------------Stack Implementation using Linked List--------------------------*/

struct Node {
    int data; //info part of the stack and queue
    Node *next; //pointer to hold the address of next ele/node of the stack and queue
};

//to create a node of the stack 
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void displayTheStack(Node* &top) {
    Node* temp = top;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

//to check whether Stack is empty or not
bool isEmpty(Node* &top) {
    if(top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//to get the top element of the Stack
void peek(Node* &top) {
    if(isEmpty(top)) {
        cout<<"No Element is present at top to display in Stack. \n";
        return;
    }

    cout<<"The top element is : "<<top->data<<endl;
}

//to push the element in the Stack
void push(Node* &top, int data) {
    Node* newNode = createNode(data);

    if(isEmpty(top)) {
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    
    cout<<"Element "<<data<<" pushed in the Stack. \n";
    cout<<"The updated Stack is.....\n";
    displayTheStack(top);
}

//to pop the top element from the Stack
void pop(Node* &top) {
    if(isEmpty(top)) {
        cout<<"Stack Underflow. \n";
        return;
    }

    else {
        Node *temp = top;
        cout<<"Element "<<top->data <<" poped from the Stack. \n";
        top=top->next;
        delete temp;
    }

    cout<<"The Updated Stack is.... \n";
    displayTheStack(top);

}

/*-------------------------------------Queue Implementation using Linked List---------------------------*/

//struct part has been created above common for both stack and queue

Node* nodeCreate(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//to check queue is empty or not
bool checkEmpty(Node* &front, Node* &rear) {
    if(front == NULL && rear == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//to display the queue
void displayQueue(Node* &front, Node* &rear) {
    if(checkEmpty(front, rear)) {
        cout<<"Queue is empty.\n";
    }
    else{
        Node* temp = front;
        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

//to insert the element in queue
void enQueue(Node* &front, Node* &rear, int data) {
    Node* newNode = nodeCreate(data);

    if(checkEmpty(front, rear)) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout<<"Element "<<data<<" pushed in the queue. \n";
    cout<<"Updated Queue is....\n";
    displayQueue(front, rear);
}

//to delete the element from the queue
void deQueue(Node* &front, Node* &rear) {
    if(checkEmpty(front, rear)){
        cout<<"Queue is Empty. \n";
        return;
    }
    else if(front == rear) {
        Node* temp = front;
        cout<<"Element "<<temp->data<<" removed from the queue. \n";
        front = rear = 0;
        delete temp;
    }
    else{
        Node* temp = front;
        front = front->next;
        temp->next = NULL;
        cout<<"Element "<<temp->data<<" removed from the queue. \n";
        delete temp;
    }

    cout<<"Updated Queue is...\n";
    displayQueue(front, rear);
}

int main() {
    int choice, subChoice, element;

    do {
        cout << "<--------------------x---------------------------> \n";
        cout << "Enter 1 to implement Stack using Linked List.\n";
        cout << "Enter 2 to implement Queue using Linked List.\n";
        cout << "Enter 3 to exit the Program.\n";
        cout << "<--------------------x---------------------------> \n";

        cout << "Enter your choice: "; 
        cin >> choice;

        switch (choice) {
            case 1: { // Stack operations
                Node* top = NULL;
                do {
                    cout << "<--------------------x---------------------------> \n";
                    cout << "Enter 1 to Push an element onto the stack.\n";
                    cout << "Enter 2 to Pop an element from the stack.\n";
                    cout << "Enter 3 to Display the stack.\n";
                    cout << "Enter 4 to Display the top element. \n";
                    cout << "Enter 5 to exit to the main menu.\n";
                    cout << "<--------------------x---------------------------> \n";

                    cout << "Enter your sub-choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter the element to push onto the stack: ";
                            cin >> element;
                            push(top, element);
                            break;
                        case 2:
                            pop(top);
                            break;
                        case 3:
                            displayTheStack(top);
                            break;
                        case 4:
                            peek(top);
                            break;
                        case 5:
                            cout << "Exiting to the main menu...\n";
                            break;
                        default:
                            cout << "Enter a valid choice.\n";
                    }
                } while (subChoice != 5);
                break;
            }
            case 2: { // Queue operations
                Node* front = NULL;
                Node* rear = NULL;
                do {
                    cout << "<--------------------x---------------------------> \n";
                    cout << "Enter 1 to Enqueue an element into the queue.\n";
                    cout << "Enter 2 to Dequeue an element from the queue.\n";
                    cout << "Enter 3 to Display the queue.\n";
                    cout << "Enter 4 to exit to the main menu.\n";
                    cout << "<--------------------x---------------------------> \n";

                    cout << "Enter your sub-choice: ";
                    cin >> subChoice;
                    switch (subChoice) {
                        case 1 :
                            cout<<"Enter the element to insert into queue : ";cin>>element;
                            enQueue(front, rear, element);
                            break;
                        case 2:
                            deQueue(front, rear);
                            break;
                        case 3:
                            displayQueue(front, rear);
                            break;
                        case 4:
                            cout << "Exiting to the main menu...\n";
                            break;
                        default :
                            cout<<"Enter the valid choice. \n";
                    }
                } while (subChoice != 4);
                break;
            }
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Enter a valid choice.\n";
        }
    } while (choice != 3);

    return 0;
}