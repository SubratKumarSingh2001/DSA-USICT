#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* next;
};

void createLinkedList(Node* &head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;

    //if Linked List is empty only create the Node.
    if(head == NULL) {
        head = newNode;
        newNode->next = head; //because its a circular Linked List
        return;
    }

    //if LL not empty
    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; //for circular Linked List

}
void displayLinkedList(Node* head) {
    if(head == NULL) {
        cout<<"There is not a single node present to display. \n";
    }

    Node* temp = head;
    //used do-while because unable to print the last node of the Circular LL
    do{
        cout<<temp->info<<"->";
        temp = temp->next;
    }while(temp != head);

}

//insert at beginning of Circular Singly Linked List
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = NULL;
    newNode->next = head;
    head = newNode;
    temp->next = newNode;
 
    displayLinkedList(head);

}

//insert at end of circular singly linked list
void insertAtEnd(Node* &head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    } 

    Node*temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;

    displayLinkedList(head);
}

//insert at particular location of Circular singly Linked list;
void insertAfterValue(Node* &head, int targetValue, int value) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;

    Node* curr = head;
    do{
        if(curr->info != targetValue) {
            curr = curr->next;
        }
        else {
            newNode->next = curr->next;
            curr->next = newNode;
            displayLinkedList(head);
            return; // we use return print the LL and come out of loop, else stuck in infinite loop
        }

    }while(curr != head);
    
    cout<<"Target value not found enter the valid value \n ";

}

//delete the node at beginning
void deleteAtBegin(Node* &head) {
    if(head == NULL) {
        cout<<"No Node is present in Circular Linked List, So can't delete the node. \n";
    }
    
    //when there is single node present in Circular Linked List.
    if(head->next == head) {
        cout << "Deleting the only node in the list.\n";
        delete head; 
        head = NULL; 
        return;
    }

    Node* temp = head;
    head = head->next;
    Node* lastNode = temp;
    while(lastNode->next != temp) {
        lastNode = lastNode->next;
    }
    temp->next = NULL;
    lastNode->next = head;
    delete temp;

    displayLinkedList(head);
}

//delete the node from end in circular linked list
void deleteAtEnd(Node* &head) {
    if(head == NULL) {
        cout<<"No Node is present in Circular Linked List, So can't delete the node. \n";
        return;
    }

    // if single node is present 
    if(head->next == head) {
        cout<<"Deleting the only Node present \n";
        delete head;
        head = NULL;
        return;
    }
    
    Node* temp = head;
    while(temp->next->next != head) {
        temp = temp->next;
    }
    Node* lastNode = temp->next;
    lastNode->next = NULL;
    delete lastNode;
    temp->next = head;

    displayLinkedList(head);

}

//delete at particular position
void deleteParticularNode(Node* &head, int targetValue) {
    if(head == NULL) {
        cout<<"No Node is present in Circular Linked List, So can't delete the node. \n";
    }

    if(head->next == head) {
        cout<<"Deleting the only Node present in Circular LL \n";
        delete head;
        head = NULL;
        return;
    }
    
    Node* curr = head;
    Node* prev = head;
    do{
        if(curr->info != targetValue) {
            curr = curr->next;
        } 
        else{
            while(prev->next != curr) {
                prev = prev->next;
            }
            Node* forward = curr->next;
            prev->next = forward;
            curr->next = NULL;
            delete curr;
            displayLinkedList(head);
            return;
        }
    }while(curr != head);

    cout<<"Target value not found \n";
}


int main() {
    Node *head = NULL;
    int value, num, choice, targetValue;

    do{
        cout<<"\n<---------- Menu --------->\n";
        cout<<"Press 1 to create a Circular Singly Linked List \n";
        cout<<"Press 2 to display the Circular Singly Linked List \n";
        cout<<"Press 3 to Insert the element at beginninG \n";
        cout<<"Press 4 to Insert the element at end \n";
        cout<<"Press 5 to Insert the element after a particular Node \n";
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
                    cout<<"Enter the value you want to add at begin of circular Linked List :";
                    cin>>value;
                    insertAtBeginning(head, value);
                    break;
                case 4:
                    cout<<"Enter the value you want to add at end of circular Linked List :";
                    cin>>value;
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
                    cout<<"Enter the value of Node you want to delete : ";cin>>targetValue;
                    deleteParticularNode(head, targetValue);
                    break;
            } 
        } 
    }while(choice != 9);
    cout<<"--------Exiting---------";
}