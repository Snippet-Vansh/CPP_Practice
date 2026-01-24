#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
};
void insertAtTail(Node* &tail,int d)
{ 
    Node* temp =new Node(d);
    tail->next = temp;
    temp = tail->next;
}
void insertAtPositon(Node* &head,int p,int d)
{
     Node* temp = head;
     int cnt =1;

     if(p==1)
     {
        insertAtHead(head,d);
        return;
     }
     Node *temp = head;
     int cn = 1;
     while(cn<p-1)
     {
          temp = temp->next;
          cnt++;
     }
     //inserting at last
     if(temp->next = NULL)
     {
        insertAtTail(tail,d);
        return ;
     }
     //creating a node for d
     Node * nodeToinsert = new Node(d);
     nodeToinsert-> next = temp->next;
     temp->next->prev = nodeToinsert;
     temp->next = nodeToinsert;
     nodeToinsert->prev =temp;
}
void print(Node* &head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *n1 = new Node(10);
    Node *head = n1; 

    insertAtHead(head,40);
    print(head);
    insertAtHead(head,20);
    print(head);
    insertAtTail(head,30);
    print(head);
    
}