#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of Stack

class Stack
{
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    Stack() { top = -1; } // Constructor initializes stack as empty

    // Push operation
    void push(int x)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Peek (top element)
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return (top < 0);
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    if (s.isEmpty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;

    return 0;
}
