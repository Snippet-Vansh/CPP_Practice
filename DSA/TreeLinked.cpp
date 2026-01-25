#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node *right;
};
struct node* createNode(int data){
    struct node* n; // creating a node pointer
    n = new node(); // allocating memory in heap
    n->data = data; // setting the data
    n->left = NULL; // setting the left and right children to null
    n->right = NULL; 
    return n; // returning the created node
};  

int main()
{
    //constructing the root node
    // struct node *n;
    // n = new node();
    // n->left = NULL;
    // n->right = NULL;
    // constructing the first node
    // struct node *n1;
    // n1->data = 1;
    // n1 = new node();
    // n1->left = NULL;
    // n1->right = NULL;
   // constructing the second node
    // struct node *n2;
    // n2->data = 2;
    // n2 = new node();
    // n2->left = NULL;
    // n2->right = NULL;

    //creating node through function
    struct node *n = createNode(4);
    struct node *n1 = createNode(3);
    struct node *n2 = createNode(2);

    //linking the root node with n1 and n2
    n->left = n1;
    n->right = n2;
    
    
}