#include <iostream>
#include <string>
using namespace std;

struct Stack {
    char *arr;
    int top;
    int size;
};

bool isEmpty(Stack &st) {
    if(st.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void initStack(Stack &st, int size) {
    st.arr = (char*)malloc(size*sizeof(char));
    st.top = -1;
    st.size = size;
}

void push(Stack &st, char ch) {
    if(st.size - st.top > 1) {
        st.top++;
        st.arr[st.top] = ch;
    }
    else {
        cout<<"StacK Overflow...\n";
        return;
    }
}

char pop(Stack &st) {
    if(isEmpty(st)) {
        cout<<"Stack Underflow... \n";
        return '\0';
    }
    return st.arr[st.top--];
}

char peek(Stack &st) {
    if(st.top == -1) {
        return '\0'; //to show the null character 
    }
    return st.arr[st.top];
}

//function to check whether the char is an operator
bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return true;
    }
    else { 
        return false;
    }
}

//to set the precedency of operators
int precedence(char ch) {
    if(ch == '^') {
        return 3;
    }
    else if(ch == '*' || ch == '/') {
        return 2;
    }
    else if(ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

//function to convert the infix to postfix
string infixToPostfix(string infix) {
    Stack st;
    initStack(st, infix.length()); //initialize the stack having the size of infix length
    string postfix;

    for(int i=0; i<infix.length(); i++) {
        char ch = infix[i];

        //if char is an operand add to the output
        if(isalnum(ch)) {
            postfix += ch;
        }

        //if the char is "(" push in stack
        else if(ch == '(') {
            push(st, ch);
        }

        //if the char is ')' then pop and add to output till '(' is found
        else if(ch == ')') {
            while(!isEmpty(st) && peek(st) != '(') {
                postfix += pop(st);
            }
            pop(st); //to remove '(' from the stack
        }

        //if the char is an operator 
        else if(isOperator(ch)) {
            while(!isEmpty(st) && precedence(peek(st)) >= precedence(ch) ) {
                postfix += pop(st);
            }
            //when precedency that of encountered input is not more then the peek element
            push(st, ch);
        }
    }
    
    //pop all the remaining ele
    while(!isEmpty(st)) {
        postfix += pop(st);
    }

    return postfix;
}

int main() {
    string infix;
    cout<<"Enter an infix expression : ";cin>>infix;

    string postfix = infixToPostfix(infix);
    cout<<"Postfix Expression : "<<postfix<<endl;

    return 0;
}