#include <iostream>
using namespace std;
struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *n)
{
    cout << "printing the elements of linked list:" << endl;
    while (n != NULL)
    {
        cout << " Queue element are:" << n->data << endl;
        n = n->next;
    }
}
void enqueue(int val)
{
    struct node *n = new node();
    if (n == NULL)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n; // n node hai jisme f,r dono point karenge agar f null hua
        }
        r->next = n; // jo node tha vo ab next node ko point karega
        r = n;
    }
}
int dequeue()
{
    int val = -1;
    if (f == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct node *n = f; // Save current front
        f = f->next;        // Move front ahead
        val = n->data;      // Get value of dequeued node
        delete n;           // Free the memory
    }
    return val;
}
int main()
{
    // struct node *n = new node();
    linkedlisttraversal(f);
    cout << "dequeing element:" << dequeue() << endl;
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    cout << "dequeing element:" << dequeue() << endl;
    linkedlisttraversal(f);
}