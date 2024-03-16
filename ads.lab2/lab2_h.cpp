#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a node at position p.
ListNode* insertNode(ListNode* head, int x, int p) {
    ListNode* newNode = new ListNode(x);

    if (p == 0) {
        newNode->next = head;
        return newNode;
    }

    ListNode* current = head;
    int currentPosition = 0;

    while (currentPosition < p - 1 && current->next) {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to remove a node at position p.
ListNode* removeNode(ListNode* head, int p) {
    if (p == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* current = head;
    int currentPosition = 0;

    while (currentPosition < p - 1 && current->next) {
        current = current->next;
        currentPosition++;
    }

    if (current->next) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

// Function to print the entire linked list.
void printList(ListNode* head) {
    if (!head) {
        std::cout << -1 << std::endl;
        return;
    }

    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to reverse the linked list.
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to perform a left cyclic shift x times.
ListNode* cyclicLeftShift(ListNode* head, int x) {
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    if (length == 0) {
        return head;
    }

    x %= length;

    if (x == 0) {
        return head;
    }

    current = head;
    int count = 0;
    ListNode* newHead = nullptr;
    ListNode* tail = nullptr;

    while (current) {
        count++;
        if (count == length - x) {
            newHead = current->next;
            current->next = nullptr;
            tail = current;
        }
        current = current->next;
    }

    if (tail) {
        tail->next = head;
    }

    return newHead;
}

// Function to perform a right cyclic shift x times.
ListNode* cyclicRightShift(ListNode* head, int x) {
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    if (length == 0) {
        return head;
    }

    x %= length;

    if (x == 0) {
        return head;
    }

    current = head;
    int count = 0;
    ListNode* newHead = nullptr;
    ListNode* tail = nullptr;

    while (current) {
        count++;
        if (count == length - x + 1) {
            newHead = current;
        }
        if (count == length - x) {
            tail = current;
        }
        current = current->next;
    }

    if (tail) {
        tail->next = nullptr;
    }

    return newHead;
}

int main() {
    ListNode* head = nullptr;

    while (true) {
        int command;
        std::cin >> command;

        if (command == 0) {
            break;
        }

        if (command == 1) {
            int x, p;
            std::cin >> x >> p;
            head = insertNode(head, x, p);
        } else if (command == 2) {
            int p;
            std::cin >> p;
            head = removeNode(head, p);
        } else if (command == 3) {
            printList(head);
        } else if (command == 4) {
            int p1, p2;
            std::cin >> p1 >> p2;
            // To be implemented: Move node from position p1 to position p2.
        } else if (command == 5) {
            head = reverseList(head);
        } else if (command == 6) {
            int x;
            std::cin >> x;
            head = cyclicLeftShift(head, x);
        } else if (command == 7) {
            int x;
            std::cin >> x;
            head = cyclicRightShift(head, x);
        }
    }

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

