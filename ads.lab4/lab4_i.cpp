#include <iostream>
using namespace std;

struct Node {
    int key;
    int count;
    Node* left;
    Node* right;
    Node(int k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);
        if (key < root->key) root->left = insert(root->left, key);
        else if (key > root->key) root->right = insert(root->right, key);
        else root->count++; // Key already exists, increase count
        return root;
    }

    Node* findMin(Node* root) {
        while (root->left) root = root->left;
        return root;
    }

    Node* remove(Node* root, int key) {
        if (!root) return root;
        if (key < root->key) root->left = remove(root->left, key);
        else if (key > root->key) root->right = remove(root->right, key);
        else {
            if (root->count > 1) {
                root->count--; // Decrease count if it's greater than 1
            } else {
                if (!root->left) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (!root->right) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->count = temp->count;
                root->right = remove(root->right, temp->key);
            }
        }
        return root;
    }

    int count(Node* root, int key) {
        if (!root) return 0;
        if (key < root->key) return count(root->left, key);
        else if (key > root->key) return count(root->right, key);
        else return root->count;
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    int count(int key) {
        return count(root, key);
    }
};

int main() {
    int Q;
    cin >> Q;
    BST bst;

    while (Q--) {
        string query;
        int X;
        cin >> query >> X;

        if (query == "insert") {
            bst.insert(X);
        } else if (query == "delete") {
            bst.remove(X);
        } else if (query == "cnt") {
            cout << bst.count(X) << endl;
        }
    }

    return 0;
}