#include <iostream>
using namespace std;

/*--------------------------------------Circular Queue using Arrays---------------------------------*/

struct cirQueue {
    int size;
    int *arr;
    int front;
    int rear;
};

//to check whether the circular queue is empty or not
bool isEmpty(cirQueue &q) {
    return (q.front == -1);
}

//initialisation of circular queue
void cirQueInit(cirQueue &q, int size) {
    q.arr = (int*)malloc(size * sizeof(int));
    q.size = size;
    q.front = -1;
    q.rear = -1;
}

// Function to display circular queue
void displayCirQue(cirQueue &q) {
    if(isEmpty(q)) {
        cout<<"Circular Queue is empty, Nothing to display. \n";
        return;
    }
    //when front is less than rear
    if(q.front <= q.rear) {
        for(int i = q.front; i <= q.rear; i++) {
            cout<< q.arr[i] << " ";
        }
    }
    // When front is greater than rear (circular wrap-around)
    else {
        for(int i = q.front; i < q.size; i++) {
            cout<< q.arr[i] << " ";
        }
        for(int i = 0; i <= q.rear; i++) {
            cout<< q.arr[i] << " ";
        }
    }
    cout<<endl;
}

//to enqueue an element in circular queue
void enQueue(cirQueue &q, int data) {
    if((q.rear == q.size-1 && q.front == 0) || (q.front - q.rear == 1)) {
        cout<<"Circular Queue is Full.. \n";
        return;
    }
    // If queue is empty
    else if(q.front == -1) {
        q.front = q.rear = 0;
        q.arr[q.rear] = data;
    }
    // Handle circular condition
    else if(q.rear == q.size - 1 && q.front != 0) {
        q.rear = 0;
        q.arr[q.rear] = data;
    }
    // Default case for normal enqueue
    else {
        q.rear++;
        q.arr[q.rear] = data;
    }
    
    cout<<"Element "<<data<<" enqueued in the queue. \n";
    cout<<"Updated Queue is...\n";
    displayCirQue(q);
}

//to dequeue an element from a circular queue
void deQueue(cirQueue &q) {
    if(isEmpty(q)) {
        cout<<"Circular Queue is Empty. \n";
        return;
    }
    // If only one element is left
    else if(q.front == q.rear) {
        cout<<"Element "<<q.arr[q.front]<<" dequeued from the queue. \n";
        q.rear = q.front = -1;
    }
    // Handle circular condition
    else if(q.front == q.size-1) {
        cout<<"Element "<<q.arr[q.front]<<" dequeued from the queue. \n";
        q.front = 0;
    }
    // Default case for normal dequeue
    else {
        cout<<"Element "<<q.arr[q.front]<<" dequeued from the queue. \n";
        q.front++;
    }
    
    cout<<"Updated Queue is...\n";
    displayCirQue(q);
}

/*--------------------------------------Circular Queue using Linked List---------------------------------*/

struct Node{
    int data;
    Node *next;
};

//to create a Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//to check whether queue is empty or not
bool emptyCheck(Node* &front, Node* &rear) {
    return (front == NULL && rear == NULL);
}

//to display the circular queue
void displayQueue(Node* &front, Node* &rear) {
    if(emptyCheck(front, rear)) {
        cout<<"Queue is empty, nothing to display. \n";
        return;
    }

    Node* temp = front;
    do{
        cout<< temp->data << "->";
        temp =temp->next;
    }while(temp != front);
    cout<<endl;
}

//to enqueue the element in queue
void Enqueue(Node* &front, Node* &rear, int data) {
    Node* newNode = createNode(data);

    if(emptyCheck(front, rear)) {
        front = newNode;
        rear = newNode;
        rear->next = front; // form a circle
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain the circular nature
    }

    cout<<"Element "<< data <<" enqueued in the circular queue. \n";
    cout<<"The updated queue is.... \n";
    displayQueue(front, rear);

}

//to dequeue the element in queue
void Dequeue(Node* &front, Node* &rear) {
    if(emptyCheck(front, rear)) {
        cout<<"Queue is empty...\n";
        return;
    }
    else if(front == rear) {
        Node* temp = front;
        cout<<"Element "<<temp->data<<" dequeued from the queue.\n";
        front = rear = NULL;
        delete temp; // freeing the node
    }
    else {
        Node* temp = front;
        front = front->next;
        rear->next = front; // maintain circular nature
        cout<<"Element "<<temp->data<<" dequeued from the queue.\n";
        delete temp; // freeing the node
    }
    
    cout<<"The updated Queue is... \n";
    displayQueue(front, rear);
}

int main() {
    int choice, subChoice, element, size;
    
    do {
        cout<<"<--------------------x---------------------------> \n";
        cout<<"Enter 1 to implement Circular Queues using Arrays. \n";
        cout<<"Enter 2 to implement Circular Queues using Linked List. \n";
        cout<<"Enter 3 to exit the Program. \n";
        cout<<"<--------------------x---------------------------> \n";

        cout<<"Enter your choice : ";cin >> choice;
        switch(choice) {
            case 1: {
                cout<<"Enter the size of the array: "; cin >> size;
                cirQueue q;
                cirQueInit(q, size);
                do {
                    cout<<"<--------------------x---------------------------> \n";
                    cout<<"Enter 1 to Enqueue an element in circular queue. \n";
                    cout<<"Enter 2 to Dequeue an element from the circular queue. \n";
                    cout<<"Enter 3 to exit to the main menu. \n";
                    cout<<"<--------------------x---------------------------> \n";

                    cout<<"Enter your sub-choice: "; cin >> subChoice;
                    switch(subChoice) {
                        case 1:
                            cout<<"Enter the element to enqueue in circular queue: "; 
                            cin >> element;
                            enQueue(q, element);
                            break;
                        case 2:
                            deQueue(q);
                            break;
                        case 3:
                            cout<<"Exiting to the main menu...\n";
                            break;
                        default:
                            cout<<"Enter a valid choice.\n";
                    }
                } while(subChoice != 3);
                break;
            }
            case 2: {
                Node *front = NULL;
                Node *rear = NULL;
                do{
                    cout<<"<-----------------------x------------------->\n";
                    cout<<"Enter 1 to Enqueue the element in Circular Queue. \n";
                    cout<<"Enter 2 to Dequeue the element from Circular Queue. \n";
                    cout<<"Enter 3 to exit to the main menu. \n";
                    cout<<"<-----------------------x------------------->\n";

                    cout<<"Enter the sub-choice : ";cin>>subChoice;
                    switch(subChoice) {
                        case 1:
                            cout<<"Enter the element you want to add : ";cin>>element;
                            Enqueue(front, rear, element);
                            break;
                        case 2:
                            Dequeue(front, rear);
                            break;
                        case 3:
                            cout<<"Exiting to the main menu... \n";
                            break;
                        default :
                            cout<<"Enter the valid choice. \n";
                    }
                }while(subChoice != 3);
                break;
            }
            case 3:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Enter a valid choice.\n";
        }
    } while(choice != 3);

    return 0;
}
