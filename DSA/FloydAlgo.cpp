#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void removeCycle(Node* head) {
    Node* slow = head, *fast = head;
    bool cycle = false;

    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { cycle = true; break; }
    }

    if (!cycle) return;

    // Find start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Find last node of cycle
    while (fast->next != slow) {
        fast = fast->next;
    }

    fast->next = NULL; // remove cycle
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // cycle created

    removeCycle(head);
    cout << "Cycle removed successfully!\n";

    cout << "Linked List after cycle removal: ";
    printList(head);

    return 0;
}
