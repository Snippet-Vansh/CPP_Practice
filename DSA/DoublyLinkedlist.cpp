#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    //destructor
    ~Node()
    {
       int value = this->data;
       //memory free
       if(next!=NULL)
       {
        delete next;
        next = NULL;
    }
    cout <<"memory is free for node with data "<<value<<endl;
    }
};
void createANode(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;

    
}
// length of a linked list
int getlength(Node* head)
{
    int len =0;
    Node *temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
//traversing a linked list
void print(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}
void insertAtHead(Node * &head,int d)
{
    Node * temp = new Node(d);
    temp->next =head;
    head->prev = temp;
    head = temp;
    
}
void insertAtTail(Node *&tail,int d)
{
    Node * temp = new Node(d);
    tail->next = temp ;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(Node *&head,Node* &tail,int p,int d)
{
    //insert at start
    if(p==1)
    {
        insertAtHead(head,d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while(cnt<p-1)
    {
        temp = temp->next;
        cnt++;
    }
    //inserting at last
    if(temp->next=NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    //creating a node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next =temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev=temp;
}
// deletion in doubly linkedlist
void deleteNode(Node* &head,int p)
{
    // deleting firt or start node
    if(p==1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next= NULL;
        delete temp;
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
       curr->prev =NULL;
       prev->next = curr->next;
       curr->next =NULL;
        delete curr;
    }
    
}
int main()
{
    Node *n1 = new Node(11);
    Node *head = n1;
    Node *tail = n1;
    print(head);
    cout<<"length is "<<getlength(head)<<endl;
    insertAtHead(head,22);
    print(head);
    insertAtHead(head,33);
    print(head);

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    insertAtHead(head,44);
    print(head);
    insertAtTail(tail,55);
    print(head);
    insertAtPosition(head,tail,1,67);
    print(head);
    deleteNode(head,3);
    print(head);
    insertAtPosition(head,tail,1,34);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    deleteNode(head,1);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
}