#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert values into the Binary Search Tree (BST)
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to check if a path exists in the BST
bool isPathAvailable(TreeNode* root, const string& path) {
    TreeNode* current = root;
    int index = 0;

    while (current != nullptr && index < path.length()) {
        if (path[index] == 'L') {
            current = current->left;
        } else if (path[index] == 'R') {
            current = current->right;
        }
        index++;
    }

    return current != nullptr && index == path.length();
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> values(N);
    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        cin >> values[i];
        root = insert(root, values[i]);
    }

    for (int i = 0; i < M; i++) {
        string path;
        cin >> path;
        if (isPathAvailable(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

