#include <iostream>
using namespace std;

int stack[5];   // stack array
int top = -1;   // top points to last element

// push function
void push(int value) {
    if (top == 4) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed\n";
    }
}

// pop function
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << stack[top] << " popped\n";
        top--;
    }
}

// peek function
void peek() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << stack[top] << endl;
}

// display function
void display() {
    if (top == -1)
        cout << "Stack is empty\n";
    else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();
    display();
    pop();
    peek();
    display();
    return 0;
}
