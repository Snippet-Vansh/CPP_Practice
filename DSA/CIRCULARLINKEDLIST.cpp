#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }  
};
void deleteList(Node* &tail)
{
    if(tail == NULL) return;

    Node* curr = tail->next;
    tail->next = NULL; // Break the circle

    while(curr != NULL)
    {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    tail = NULL;
}

void insertNode(Node* &tail,int element,int d)
    {
        if(tail==NULL)
        {
            Node * newNode = new Node(d);
            tail = newNode;
            newNode->next =newNode;
        }
        else{
            Node *curr = tail;
            while(curr->data!=element)
            {
                curr = curr->next;
            }
            //elemnt found
            Node * temp = new Node(d);
            temp->next = curr ->next;
            curr->next = temp;
        }
    }
    // void print(Node* tail)
    // {
    //     Node *temp = tail;
    //     do
    //     {
    //         cout<<tail->data<<" ";
        
    //     } while (tail != NULL);
    //     cout<<endl;
    void print(Node* tail)
{
    if (tail == NULL) return; // Empty list check

    Node* temp = tail->next; // Start from the node after tail
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail->next); // Stop when we complete the circle

    cout << endl;
}

int main()
{
   Node* tail = NULL;

   insertNode(tail,5,3);
   print(tail);
   return 0;
}