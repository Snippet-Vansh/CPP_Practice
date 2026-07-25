#include<iostream>
using namespace std;
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *n)
{
    if(n==NULL)
    {
        return 0;
        return n->height;
    }
}

struct node *createnode(int key)
{
    struct node *n = new node();
    n->left = NULL;
    n->right = NULL;
    n ->key = key;
    n->height = 1;
     // new node is initially added at leaf
         return n;
    }

int getbalancefactor(struct node *n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
struct node *leftrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    x->right = y;
    y->left = t2;   
}
int main()
{
    
}