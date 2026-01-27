#include <iostream>
using namespace std;
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
// void inorder(struct node *root)
// {
//   if (root != NULL)
//   {
//     // recursive function
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
//   }
// }
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            // cout<<"it is not a bst"<<endl;
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        // cout<<"it is a bst"<<endl;
        return 1;
    }
}
struct node *searchIter(struct node *root, int key)
{
    while (root!=NULL)
    {
        if (key == root->data)
        {
            return root; //found the element/key
        } 
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    // creating node through function
    struct node *n = createNode(5);
    struct node *n1 = createNode(3);
    struct node *n2 = createNode(1);
    struct node *n3 = createNode(4);
    struct node *n4 = createNode(6);
    // tree diagram
    //            5
    //          /  \
    //       3    6
    //       /  \
    //   1    4

    // linking the root node with n1 and n2
    n->left = n1;
    n->right = n4;
    n1->left = n2;
    n1->right = n3;
    // inorder(n);
    struct node *result = searchIter(n,6);
    if (result != NULL)
    {

        cout << "Found:" << result->data << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }
    return 0;
}