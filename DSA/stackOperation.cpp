#include <iostream>
#include<stdio.h>
using namespace std;
struct stack {
    int top;
    int size;
    int* arr;

};
//stack is empty
int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
    {
        return 1; // stack is empty
    }
    else{
        return 0;
    }
}
// to check whether the stack is full or not
int isFull(struct stack* ptr)
{
if(ptr->top==ptr->size-1)
{
return 1;
}else{
return 0;
}
}
// push operation
void push(struct stack *ptr,int a)
{
    struct stack s;
    s.top = -1;
    s.size = 5;
    s.arr = new int[s.size];
if(isFull(&s))
{
    cout<<"stack overflow"<<endl;
}
else{
   ptr->top++;
   ptr->arr[ptr->top]=a;
     
}
};
// pop operation
int pop( struct stack s,int val)
{
    struct stack s;
    s.top = -1;
    s.size = 5;
    s.arr = new int[s.size];   
    if(isEmpty(&s))
    {
        cout<<"stack underflow"<<endl;
    }
    else{
        int val = s.arr[s.top]; //s.arr[s.top]; iska mtlb s->arr ka top store the top most value
        s.top--;
        return val;
    }
    } ;

    //peek operation
    int peek(struct stack *s,int i)
{
    int arrayInd = s->top-i-1;
    if(arrayInd < 0)
    {
        cout<<"Not a valid position"<<endl;
        return -1;
    }
    else
    {
        return s->arr[s->top-1];
    }
};
int main()
{
 struct stack *s = new stack();
 s->size=5;
    s->top=-1;
    s->arr=new int[s->size]; 
    cout<<"stack has been created successfully"<<endl;
   //psushing element
   s->arr[0]=5;
   s->top++;
    if(isEmpty(s))
    {
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    return 0;
    printf("%d",isEmpty(s));
   push(s,1);
   push(s,3);
   push(s,2);
   push(s,4);
   push(s,6);
   push(s,7);
  for(int j=1;j<=s->top+1;j++)
  {
      cout<<"the value at position is "<<peek(s,j);
  }

}