#include <iostream>

using namespace std;

// Define the structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new element at the end of the linked list
Node* insertNode(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Function to remove every second element from the linked list
Node* removeEverySecond(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;
    bool removeNext = false;

    while (current) {
        if (removeNext) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
        removeNext = !removeNext;
    }

    return head;
}

// Function to print the elements of the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        head = insertNode(head, val);
    }

    head = removeEverySecond(head);
    printList(head);

    return 0;
}

