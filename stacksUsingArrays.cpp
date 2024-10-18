#include <iostream>
using namespace std;

//stacks using arrays as dynamic arrays

struct Stack {
    int *arr; //dynamic arrays for stack creation
    int size; //max size of an array i.e max ele an stack can hold not the number of element in the array
    int top;  //stack can be access for top i.e to peek the top ele present
};

//to get the size of the stack 
int getSize(Stack &st) {
    return st.top+1;
}

//to get the peek element
int peek(Stack &st) {
    if(st.top == -1) {
        cout<<"Stack is Empty. There is no Element present... \n";
        return 0;
    }
    return st.arr[st.top];
}

//to check stack is empty or not
bool isEmpty(Stack &st) {
    if(st.top == -1) {
        return true;
    }
    else { 
        return false;
    }
}

//to display the stack elements
void displayTheStack(Stack &st) {
    if(isEmpty(st)) {
        cout<<"Stack is empty.. \n";
        int stackSize = getSize(st);
        cout<<"The size of a Stack is :" <<stackSize;
    }

    for(int i=st.top; i>=0; i--) {
        cout<<st.arr[i] <<" ";
    }
    cout<<endl;
}

//initializing the stack
void initTheStack(Stack &st, int size) {
    st.arr = (int*)malloc(size * sizeof(int));
    st.size = size;
    st.top = -1;
}
 
//push the element in the Stack
void push(Stack &st, int element) {
    if(st.size - st.top > 1) {
        st.top++;
        st.arr[st.top] = element;
    }
    else{
        cout<<"Stack Overflow.....\n";
        return;
    }
    
    cout<<"Element "<<element<<" pushed in the stack. \n";
    cout<<"The updated Stack is.. \n";
    displayTheStack(st);
}

//pop the top most element from the stack
void pop(Stack &st) {
    if(isEmpty(st)) {
        cout<<"Stack Underflow.....\n";
        return;
    }
    cout<<"Element "<<st.arr[st.top]<<" pop from the Stack. \n";
    st.top--;
    cout<<"The updated stack is...\n";
    displayTheStack(st);
}

int main() {
    int size, element, choice;
    cout<<"Enter the maximum size of any array: ";cin>>size;

    Stack st;
    initTheStack(st, size);

    do {
        cout<<"<--------------x------------------> \n";
        cout<<"Enter 1 to push an element in a Stack. \n";
        cout<<"Enter 2 to pop an element in a Stack. \n";
        cout<<"Enter 3 to get the peek i.e top element of Stack. \n";
        cout<<"<--------------x------------------> \n";

        cout<<"Enter the choice : "; cin>> choice;
        if(choice<1 || choice >3) {
            cout<<"Enter the valid choice....\n";
        }
        switch(choice) {
            case 1: 
                cout<<"Enter the element you want to add is Stack : ";cin>>element;
                push(st, element);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                int peekElement = peek(st);
                cout<<"The Top Element is : "<<peekElement<<endl;
                break;
        }
    } while(choice !=4);
    cout<<"Program Exist....\n";
}