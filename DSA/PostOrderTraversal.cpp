#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n; // creating a node pointer
    n = new node(); // allocating memory in heap
    n->data = data; // setting the data
    n->left = NULL; // setting the left and right children to null
    n->right = NULL;
    return n; // returning the created node
};
void postorder(struct node *root)
{
  if(root !=NULL)
  {
      // recursive function
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
  }  
}
int main()
{
    // creating node through function
    struct node *n = createNode(4);
    struct node *n1 = createNode(1);
    struct node *n2 = createNode(5);
    struct node *n3 = createNode(2);
    struct node *n4 = createNode(6);
  // tree diagram
    //     4
    //   /  \
    //   1   6
    // /  \
    // 5   2

    // linking the root node with n1 and n2
    n->left = n1;
    n->right = n4;
    n1->left = n2;
    n1->right = n3;
    postorder(n);
   
}