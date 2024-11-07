#include <iostream>
using namespace std;

struct Queue {
    int *arr; //dynamic creation of an array;
    int size; //maximum size of an array
    int front; //variable indicating the first element of the queue
    int rear; //variable indicating the last element of the queue
};

//to check whether the queue is empty or not
bool isEmpty(Queue &q) {
    if(q.front == q.rear) {
        return true;
    }
    else {
        return false;
    }
}

//to get the front element of a queue 
void getFront(Queue &q) {
    if(isEmpty(q)) {
        cout<<"Queue is Empty. No Front element is present. \n";
    }
    else {
        cout<<"The Front element is: " << q.arr[q.front]<<endl;
    }
}

//display the queue
void displayQueue(Queue &q) {
    if(isEmpty(q)) {
        cout<<"Queue is Empty. No element is present to display.\n";
    }
    else{
        for(int i=q.front; i<q.rear; i++) {
            cout<<q.arr[i]<<" ";
        }
        cout<<endl;
    }
}

//initialisation of queue
void initQueue(Queue &q, int size) {
    q.arr = (int*)malloc(size*sizeof(int));
    q.size = size;
    q.front = 0;
    q.rear = 0;
}

//enqueue is to insert an element at the rear end of queue.
void enQueue(Queue &q, int data) {
    if(q.rear == q.size) {
        cout<<"Queue is Full....\n";
        return;
    }
    else{
        q.arr[q.rear] = data;
        q.rear++;
    }
    cout<<"Element "<<data<<" enqueued in the queue. \n";
    cout<<"Updated Queue is...\n";
    displayQueue(q);
}

//dequeue is to delete the front element from the queue
void deQueue(Queue &q) {
    if(isEmpty(q)) {
        cout<<"Queue is Empty.....\n";
    }
    else{
        cout<<"Element "<<q.arr[q.front]<<" dequeued from the queue. \n";
        q.front++;
        if(isEmpty(q)) {
            q.front = 0;
            q.rear = 0;
        }
    }

    cout<<"Updated Queue is...\n";
    displayQueue(q);
}

int main() {
    int choice, element,size;
    
    cout<<"Enter the size of an array : ";cin>>size;
    Queue q;
    initQueue(q, size);

    do{ 
        cout<<"<--------------------x--------------------->\n";
        cout<<"Enter 1 to Enqueue an element in the queue. \n";
        cout<<"Enter 2 to Dequeue an element from the queue. \n";
        cout<<"Enter 3 to check whether the queue is empty or not. \n";
        cout<<"Enter 4 to get the front element of a queue. \n";
        cout<<"Enter 5 to exist the Program. \n";
        cout<<"<--------------------x--------------------->\n";

        cout<<"Enter the choice : ";cin>>choice;
        switch(choice) {
            case 1: 
                cout<<"Enter the element you want to enqueue in the queue : ";cin>>element;
                enQueue(q, element);
                break;
            case 2:
                deQueue(q);
                break;
            case 3:
                if(isEmpty(q)) {
                    cout<<"Queue is Empty. \n";
                }
                else {
                    cout<<"Queue is not Empty. \n";
                }
                break;
            case 4: 
                getFront(q);
                break;
            case 5:
                cout<<"Program Exist....\n";
                break;
            default:
                cout<<"Enter the valid choice. \n";
        }
    }while(choice != 5);
}