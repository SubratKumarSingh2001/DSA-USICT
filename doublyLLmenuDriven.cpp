#include <iostream>
using namespace std;

struct Node {
    int info; //date inside the node
    Node* prev; // pointer hold the address of prev node
    Node* next; // pointer hold the address of next node
};

//create a node
Node* createNode(int value) {

    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->info = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}

//create a doubly linked list
void createLinkedList(Node* &head, int value) {
    Node* newNode = createNode(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}

//display the circular linked list
void displayLinkedList(Node* &head) {

    if(head == NULL) {
        cout<<"No Node is present to display \n";
    }

    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
}

//insert at begin of doubly Linked list
void insertAtBegin(Node* &head, int value) {
    Node* newNode = createNode(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    displayLinkedList(head);
}

//insert at end of doubly linked list
void insertAtEnd(Node* &head, int value) {
    Node* newNode = createNode(value);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp; 
    
    displayLinkedList(head);

}

//insert the node after the particular node
void insertAfterValue(Node* &head, int targetValue, int value) {
    Node* newNode = createNode(value);

    Node* curr = head;
    while(curr != NULL && curr->info != targetValue) {
        curr = curr->next;
    }

    if(curr != NULL) {
        if(curr->next == NULL) {
            curr->next = newNode;
            newNode->prev = curr;
        }
        else {
            Node* forward = curr->next;
            newNode->next = forward;
            forward->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
    }
    else {
        cout<<"The target value not found, Please enter the correct value. \n";
        return;
    }
   
    displayLinkedList(head);
    
}
 
//delete the begin node of doubly LL
void deleteBeginNode(Node* &head) {
    if(head == NULL) {
        cout<<"Doubly LL is empty, can't delete a node. \n";
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
    head->prev = NULL;
    delete temp;

    displayLinkedList(head);
}

// delete the end node of doubly LL
void deleteEndNode(Node* &head) {
    if(head == NULL) {
        cout<<"Doubly LL is empty, can't delete a node. \n";
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
    lastNode->prev = NULL;
    delete lastNode;

    displayLinkedList(head);
}

//delete the particular node
void deleteParticularNode(Node* &head, int targetValue) {
    if(head == NULL){
        cout<<"Doubly Linked List is empty, So Target value is not present and can't delete. \n";
    }
    
    //single node is present
    if(head->next == NULL) {
        cout<<"Deleting the only node present.... \n";
        delete head;
        head = NULL;
        return;
    }

    Node* curr = head;
    while(curr != NULL && curr->info != targetValue) {
        curr =curr->next;
    }
    if(curr != NULL) {
        if(curr->next == NULL) {
            Node* secondLast = curr->prev;
            secondLast->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
        else{
            Node* prevNode = curr->prev;
            curr->next->prev = prevNode;
            prevNode->next = curr->next;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }
    else {
        cout<<"The target value not found, Please enter the correct value. \n";
        return;
    }
    
    displayLinkedList(head);
}


int main() {
    Node *head = NULL;
    int value, num, choice, targetValue;

    do{
        cout<<"\n<---------- Menu --------->\n";
        cout<<"Press 1 to create a Doubly Linked List \n";
        cout<<"Press 2 to display the Doubly Linked List \n";
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