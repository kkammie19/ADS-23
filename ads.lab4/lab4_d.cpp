#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
    } else {
        if (value < root->value) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }
}

void sumValuesByLevel(TreeNode* root, int level, vector<long long>& levelSums) {
    if (root == nullptr) return;

    if (level >= levelSums.size()) {
        levelSums.push_back(root->value);
    } else {
        levelSums[level] += root->value;
    }

    sumValuesByLevel(root->left, level + 1, levelSums);
    sumValuesByLevel(root->right, level + 1, levelSums);
}

int findMaxLevel(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(findMaxLevel(root->left), findMaxLevel(root->right)) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        insert(root, permutation[i]);
    }

    int maxLevel = findMaxLevel(root);
    vector<long long> levelSums(maxLevel, 0);

    sumValuesByLevel(root, 0, levelSums);

    cout << maxLevel << endl;
    for (int levelSum : levelSums) {
        cout << levelSum << " ";
    }
    cout << endl;

    return 0;
}

