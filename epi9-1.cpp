/* EPI9-1: Design a stack that supports a max operation, which returns the 
 * maximum value stored in the stack, and throws an exception if the stack is 
 * empty. Assume elements are comparable. All operations must be O(1) time. If 
 * the stack contains n elements, you can use O(n) space, in addition to what 
 * is required for the elements themselves. */
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    node* below;
} node;

class Stack {
    public:
        Stack();
        int getMax();
        int pop();
        void push(int);
        void printStack();
    private:
        node *top;
        node *max;
};

Stack::Stack() {
    top = NULL;
    max = NULL;
}

int Stack::pop() {
    if (top == NULL) {
        throw length_error("Empty stack.");
    } else {
        int topdatacpy = top->data;
        delete top;
        top = top->below;
        return topdatacpy;
    }
}

void Stack::push(int newNum) {
    node *newnode = new node;
    newnode->data = newNum;
    if (top == NULL) {
        newnode->below = NULL;
    } else {
        newnode->below = top;
    }
    top = newnode;
    if (max == NULL) {
        max = newnode;
    }
    else if (max->data < newNum) {
        max = newnode;
    }
}

void Stack::printStack() {
    node *topcpy = top;
    while (topcpy != NULL) {
        cout << topcpy->data << endl;
        topcpy = topcpy->below;
    }
}

int Stack::getMax() {
    if (max == NULL) {
        throw length_error("Empty stack.");
    } else {
        return max->data;
    }
}

int main() {
    Stack* s = new Stack();
    s->push(4);
    s->push(1);
    s->push(2);
    s->printStack();
}
