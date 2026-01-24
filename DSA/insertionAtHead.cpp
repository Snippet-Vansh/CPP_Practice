#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    
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
// deletion in doubly linkedlist
void deleteNode(Node* &head,int p)
{
    // deleting firt or start node
    if(p==1)
    {
        Node* temp = head;
       head = head -> next;
       delete temp ;
    }
    else
    {
        //deleting any middle node or last node
        Node * curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt <=p)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }

}
int main()
{
    Node *n1 = new Node(10);
    Node *head = n1;
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,20);
    print(head);
}
