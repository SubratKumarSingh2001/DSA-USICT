#include <iostream>
using namespace std;

struct Node {
    int info; //store info part of node
    Node *next; // hold the address of next node
};

// creating a linked list by taking input from user
void createLinkedList(Node* &head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->info = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else{
        Node*temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//displaying the linked list 
void displayLinkedList(Node* &head) {
    if(head == NULL) {
        cout<<"No elements are present to display. \n";
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
}

//number of nodes in the linked list
int countNodes(Node* &head) {
    int count=0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// insert at head
void insertAtHead(Node* &head, int value) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = head;
    head = newNode;
    
    displayLinkedList(head);
}

//insert at tail
void insertAtEnd(Node* &head, int value){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next =NULL;

    if(head == NULL){
        head = newNode;
    }
    else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    displayLinkedList(head);
}

//insert at specific position
void insertAfterValue(Node* &head, int targetValue, int value) {

    Node* newNode =  (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;

    Node* curr = head;
    //first we will find the target value and point it with curr pointer and also check the curr in null
    // not
    while(curr != NULL && curr->info != targetValue) {
        curr = curr->next;
    }
    
    if(curr != NULL) {
        newNode->next = curr->next;
        curr->next = newNode;
    }
    else {
        cout<<"The Targeted value not found, Please enter the correct value. \n";
        return;
    }
    
    
    displayLinkedList(head);
}

//delete at beginning
void deleteAtBegin(Node* &head) {
    if(head == NULL) {
        cout<<"Linked List is empty can't delete a node. \n";
    }

    if(head->next == NULL) {
        cout<<"Deleting the only node present.... \n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;

    displayLinkedList(head);
}

//delete at end of Linked List
void deleteAtEnd(Node* & head) {
    if(head == NULL) {
        cout<<"Linked List is empty can't delete a node. \n";
    }

    if(head->next == NULL) {
        cout<<"Deleting the only node present.... \n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* lastNode = temp->next;
    temp->next = NULL;
    delete lastNode;

    displayLinkedList(head);
}

//delete the specific value
void deleteParticularNode(Node* &head, int targetValue) {

    if(head == NULL){
        cout<<"The Linked List is empty, So Target value is not present and can't delete. \n";
    }

    if(head->next == NULL) {
        cout<<"Deleting the only node present.... \n";
        delete head;
        head = NULL;
        return;
    }
    
    // we want to delete the specific value
    Node* curr = head;
    
    //find the target value you want to delete;
    while(curr != NULL && curr->info != targetValue) {
        curr = curr->next;
    }

    Node* prev = head;
    while(prev->next != curr) {
        prev = prev->next;
    }

    if(curr != NULL) {
        Node* forward = curr->next;
        prev->next = forward;
        curr->next = NULL;
        delete curr;
    }
    else {
        cout<<"The target node is not found to delete. Please enter valid node. \n";
        return;
    }

    displayLinkedList(head);

}

//reverse the linked list
Node* reverseLinkedList(Node* &head) {
    if(head == NULL) {
        cout<<"No Node is present. Reversing the Linked List is not possible. \n";
    }

    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev; //because now we are out of the loop means our last node is prev and will act
    // as head node to print for reverse
}

int main() {

    Node *head = NULL;
    int targetValue, value, num, choice, position;

    do{
        cout<<"\n<---------- Menu --------->\n";
        cout<<"Press 1 to create a Singly Linked List \n";
        cout<<"Press 2 to display the Singly Linked List \n";
        cout<<"Press 3 to Insert the element at beginning \n";
        cout<<"Press 4 to Insert the element at end \n";
        cout<<"Press 5 to Insert the element after a particular node \n";
        cout<<"Press 6 to Delete the element at beginning \n";
        cout<<"Press 7 to Delete the element at end \n";
        cout<<"Press 8 to Delete the particular Node \n";
        cout<<"Press 9 to reverse the Linked List \n";
        cout<<"Press 10 to display number of nodes in Linked List \n";
        cout<<"\n<---------- X --------->\n";
         
        cout<<"Enter the choice : "; cin>>choice;
        if(choice !=1 && choice !=2 && choice !=3 && choice !=4 && choice !=5 && choice !=6 && choice !=7 
           && choice !=8 && choice !=9 && choice !=10 ) {
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
                    insertAtHead(head, value);
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
                    deleteAtBegin(head);
                    break;
                case 7:
                    deleteAtEnd(head);
                    break;
                case 8:
                    cout<<"Enter the target value which you want to delete: ";cin>>targetValue;
                    deleteParticularNode(head, targetValue);
                    break;
                case 9:
                    head = reverseLinkedList(head);
                    displayLinkedList(head);
                    break;
                case 10:
                    int count = countNodes(head);
                    cout<<"The number of nodes in Linked List are : "<<count;
                    break;
            }
        }
    }while(choice != 11);
    cout<<"--------Exiting---------";
}