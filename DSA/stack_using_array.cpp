#include <iostream>
using namespace std;
struct stack {
    int top;
    int size;
    int* arr;
};
int isEmpty(struct stack* ptr) {
    if(ptr->top==-1)
    {
        return 1;

    }
    else{
        return 0;
    }
}
int isfull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
    
int main()
{
    struct stack s;
    s.size= 5;
    s.top= -1;
    s.arr= new int[s.size];
    // s.arr[++s.top]=10;
    // s.arr[++s.top]=20;

    if(isEmpty(&s))
    {
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }


}    