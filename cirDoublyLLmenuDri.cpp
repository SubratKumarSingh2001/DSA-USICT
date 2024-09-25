#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = newNode;
    newNode->prev = newNode;
}

//create a circular doubly linked list
void createLinkedList(Node* &head, int value) {
    Node* newNode = createNode(value);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;

}

//display the circular doubly linked list
void displayLinkedList(Node* &head){
    if(head == NULL) {
        cout<<"Linked List in empty, No Node is present to display. \n";
        return;
    }
    
    Node* temp = head;
    do{
        cout<<temp->info<<"->";
        temp = temp->next;

    } while(temp != head);
}

//insert at the beginning of circular doubly LL
void insertAtBegin(Node* &head, int value) {
    Node* newNode = createNode(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    temp->next = head;
    head->prev = temp;

    displayLinkedList(head);
}

//insert at the end of circular doubly Linked List
void insertAtEnd(Node* &head, int value) {
    Node* newNode = createNode(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;

    displayLinkedList(head);
}

//insert after a particular node in linked list
void insertAfterValue(Node* &head, int targetValue, int value) {
    Node* newNode = createNode(value);
    
    Node* curr = head;
    while(curr != NULL && curr->info != targetValue) {
        curr = curr->next;
    }
    if(curr != NULL) {
        curr->next->prev = newNode;
        newNode->next = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
    }
    else {
        cout<<"Targeted value not found, Please enter the valid value. \n";
        return;
    }
    
    displayLinkedList(head);

}

// delete the beginning node of circular doubly linked list
void deleteBeginNode(Node* &head) {
    if(head == NULL) {
        cout<<"Circular Doubly LL is empty, can't delete a node. \n";
    }

    if(head->next == head) {
        cout<<"Deleting the only Node present..... \n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* curr = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    head->prev = temp;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;

    displayLinkedList(head);

}

// delete the end node of circular linked list
void deleteEndNode(Node* &head) {
    if(head == NULL) {
        cout<<"Circular Doubly LL is empty, can't delete a node. \n";
    }

    if(head->next == head) {
        cout<<"Deleting the only Node present..... \n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != head) {
        temp = temp->next;
    }
    Node* lastNode = temp->next;
    temp->next = head;
    head->prev = temp;
    lastNode->next = NULL;
    lastNode->prev = NULL;
    delete lastNode;

    displayLinkedList(head);
}

//delete the particular node of circular doubly linked list
void deleteParticularNode(Node* &head, int targetValue) {
    if(head == NULL) {
        cout<<"Circular Doubly LL is empty, can't delete a node. \n";
    }

    //when single node is present delete it
    if(head->next == head) {
        cout<<"Deleting the only Node present..... \n";
        delete head;
        head = NULL;
        return;
    }

    Node* curr = head;
    do{
        if(curr->info != targetValue) {
            curr = curr->next;
        }
        else {
            Node* prevNode = curr->prev;
            curr->next->prev = prevNode;
            prevNode->next = curr->next;
            curr->next = NULL;
            curr->next = NULL;
            delete curr;
            displayLinkedList(head);
            return;
        }
    }while(curr != head);

    cout<<"Target value not found. Please enter the correct target value. \n";

}

int main() {
    Node *head = NULL;
    int value, num, choice, targetValue;

    do{
        cout<<"\n<---------- Menu --------->\n";
        cout<<"Press 1 to create a Circular Doubly Linked List \n";
        cout<<"Press 2 to display the Circular Doubly Linked List \n";
        cout<<"Press 3 to Insert the element at beginning \n";
        cout<<"Press 4 to Insert the element at end \n";
        cout<<"Press 5 to Insert the element after particular Node \n";
        cout<<"Press 6 to Delete the element at beginning \n";
        cout<<"Press 7 to Delete the element at end \n";
        cout<<"Press 8 to Delete the particular Node \n";
        cout<<"\n<---------- X --------->\n";
         
        cout<<"Enter the choice : "; cin>>choice;
        if(choice !=1 && choice !=2 && choice !=3 && choice !=4 && choice !=5 && choice !=6 && choice !=7 &&
           choice != 8) {
            cout<<"Enter the valid choice \n";
        }
        else {
            switch(choice) {
                case 1:
                    cout<<"Enter how many elements you want in linked list :";cin>>num;
                    for(int i=1; i<=num; i++) {
                        cin>>value;
                        createLinkedList(head, value);
                    }
                    break;
                case 2:
                    displayLinkedList(head);
                    break;
                case 3:
                    cout<<"Enter the value you want to add at beginning : ";cin>>value;
                    insertAtBegin(head, value);
                    break;
                case 4:
                    cout<<"Enter the value you want to add at end : ";cin>>value;
                    insertAtEnd(head, value);
                    break;
                case 5:
                    cout<<"Enter the target value after which you want to add the node : ";cin>>targetValue;
                    cout<<"Enter the value of node you want to add : ";cin>>value;
                    insertAfterValue(head, targetValue, value);
                    break;
                case 6:
                    deleteBeginNode(head);
                    break;
                case 7:
                    deleteEndNode(head);
                    break;
                case 8:
                    cout<<"Enter the target Node you want to delete: ";cin>>targetValue;
                    deleteParticularNode(head, targetValue);
                    break;
            } 
        } 
    }while(choice != 9);
    cout<<"--------Exiting---------";
}