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
    struct node *n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;

        if (prev != NULL && root->data <= prev->data)
            return 0;

        prev = root;
        return isBST(root->right);
    }
    return 1;
}

struct node *inorderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;

    if (root == NULL)
        return NULL;

    // Node found (no children)
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    // Search for the node
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    else
    {
        // Node found, perform deletion
        ipre = inorderPredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

int main()
{
    // Creating nodes
    struct node *n = createNode(5);
    struct node *n1 = createNode(3);
    struct node *n2 = createNode(6);
    struct node *n3 = createNode(2);
    struct node *n4 = createNode(4);

    // Tree structure:
    //        5
    //       / \
    //      3   6
    //     / \
    //    2   4

    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;

    cout << "Inorder before deletion: ";
    inorder(n);
    cout << endl;

    if (isBST(n))
        cout << "It is a BST" << endl;
    else
        cout << "It is not a BST" << endl;

    n = deletenode(n, 3);

    cout << "Inorder after deleting "<<endl;
    inorder(n);
    cout << endl;

    return 0;
}
