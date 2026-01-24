#include<iostream>
#include<stdio.h>
using namespace std;
 struct Node{
    int data;
    Node *next;
 };
 int isempty()
 {
   if(top==NULL){
      return 1;
   }else{
      return 0;
   }
 };
 int isfull()
 {
   struct Node *n = (struct Node *)malloc(sizeof(struct Node));
   if(n==NULL)
   {
     return 1;
   }else{
      return 0;
   }
 }
 void push()
 {
   struct Node *n=(struct Node *)malloc(sizeof(struct Node));
   if(n==NULL)
   {
      printf("stack is empty");
   }else{
      n->data =  x;
      n ->next = top;
      top = n;
   }
 }
int main() {

}