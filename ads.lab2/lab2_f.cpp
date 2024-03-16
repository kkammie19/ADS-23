#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a node at a specified position in the linked list.
ListNode* insertNodeAtPosition(ListNode* head, int data, int position) {
    ListNode* newNode = new ListNode(data);
    
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    
    ListNode* current = head;
    int currentPosition = 0;
    
    while (currentPosition < position - 1 && current->next) {
        current = current->next;
        currentPosition++;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

// Function to print the linked list.
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int data;
        std::cin >> data;
        ListNode* newNode = new ListNode(data);
        
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int data, position;
    std::cin >> data >> position;
    
    head = insertNodeAtPosition(head, data, position);
    
    // Print the updated linked list
    printLinkedList(head);
    
    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
