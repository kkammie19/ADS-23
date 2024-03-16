#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

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

void preOrder(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> gifts(n);

    for (int i = 0; i < n; i++) {
        cin >> gifts[i];
    }

    int k;
    cin >> k;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        root = insert(root, gifts[i]);
    }

    TreeNode* damirSubtree = root;
    while (damirSubtree->value != k) {
        if (k < damirSubtree->value) {
            damirSubtree = damirSubtree->left;
        } else {
            damirSubtree = damirSubtree->right;
        }
    }

    preOrder(damirSubtree);

    return 0;
}

