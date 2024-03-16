#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for a doubly linked list node.
struct Node {
    string data;
    Node* next;
    Node* prev;
    Node(const string& book) : data(book), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add a new book to the beginning of the linked list.
    void addFront(const string& book) {
        Node* newNode = new Node(book);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Add a new book to the end of the linked list.
    void addBack(const string& book) {
        Node* newNode = new Node(book);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Erase the first book in the linked list and return its name.
    string eraseFront() {
        if (!head) {
            return "error";
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        string bookName = temp->data;
        delete temp;
        return bookName;
    }

    // Erase the last book in the linked list and return its name.
    string eraseBack() {
        if (!tail) {
            return "error";
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        string bookName = temp->data;
        delete temp;
        return bookName;
    }

    // Get the name of the first book.
    string front() const {
        if (!head) {
            return "error";
        } else {
            return head->data;
        }
    }

    // Get the name of the last book.
    string back() const {
        if (!tail) {
            return "error";
        } else {
            return tail->data;
        }
    }

    // Erase all books in the linked list.
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // Destructor to free memory.
    ~DoublyLinkedList() {
        clear();
    }
};

int main() {
    DoublyLinkedList books;
    vector<string> commands;
    string command;

    while (cin >> command) {
        commands.push_back(command);
        if (command == "add_front" || command == "add_back") {
            string book;
            cin >> book;
            commands.push_back(book);
        }
    }

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "add_front") {
            string book = commands[++i];
            books.addFront(book);
            cout << "ok" << endl;
        } else if (commands[i] == "add_back") {
            string book = commands[++i];
            books.addBack(book);
            cout << "ok" << endl;
        } else if (commands[i] == "erase_front") {
            string bookName = books.eraseFront();
            if (bookName != "error") {
                cout << bookName << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (commands[i] == "erase_back") {
            string bookName = books.eraseBack();
            if (bookName != "error") {
                cout << bookName << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (commands[i] == "front") {
            cout << books.front() << endl;
        } else if (commands[i] == "back") {
            cout << books.back() << endl;
        } else if (commands[i] == "clear") {
            books.clear();
            cout << "ok" << endl;
        } else if (commands[i] == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}

