#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to perform Level Order Traversal
void levelOrder(Node* root) {
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}
