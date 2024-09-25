#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;
    return newNode;
}

void insertIntoLinkedList(Node* &head, int value) {
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

}

void displayLinkedList(Node* &head) {
    if(head == NULL) {
        cout<<"Linked List is empty, So can't display the linked list. \n";
    }

    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
}

void inputLinkedList(Node* &head) {
    int num, value;
    cout<<"Enter the num of nodes you want to add: ";cin>>num;
    for(int i=1; i<=num ; i++) {
        cout<<"Enter the values you want to add in Linked List: ";
        cin>>value;
        insertIntoLinkedList(head, value);
        cout<<endl;
    }
}

Node* mergeTheLinkedList(Node* &left, Node* &right) {
    if(left == NULL) {
        return right;
    }

    if(right == NULL) {
        return left;
    }

    Node* ans = createNode(-1);
    Node* temp = ans; //basically to iterate through left and right two different linked list

    while(left != NULL && right != NULL) {
        if(left->info <= right->info) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
    // when any of Linked list become empty just iterate the another linked list
    if(left != NULL) {
        temp->next = left;
    }
    else {
        temp->next = right;
    }

    return ans->next;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    //taking the inputs of both the linked list
    cout<<"Input the first Linked List \n";
    inputLinkedList(head1);

    cout<<"Input the second Linked List \n";
    inputLinkedList(head2);

    cout<<"The First Linked List is: \n";
    displayLinkedList(head1);

    cout<<endl;
    cout<<"The Second Linked List is: \n";
    displayLinkedList(head2);
    
    cout<<endl;
    Node* head = mergeTheLinkedList(head1, head2);
    cout<<"The result merge sorted Linked List after merging two sorted Linked List is: \n";
    displayLinkedList(head);
}