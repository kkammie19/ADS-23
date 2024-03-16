#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int findMaxWidth(TreeNode* root) {
    if (!root) return 0;

    int maxWidth = 0;

    queue<TreeNode*> levelQueue;
    levelQueue.push(root);

    while (!levelQueue.empty()) {
        int levelWidth = levelQueue.size();

        maxWidth = max(maxWidth, levelWidth);

        for (int i = 0; i < levelWidth; i++) {
            TreeNode* current = levelQueue.front();
            levelQueue.pop();

            if (current->left) levelQueue.push(current->left);
            if (current->right) levelQueue.push(current->right);
        }
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode*> nodes(n + 1, nullptr);

    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (!nodes[x]) {
            nodes[x] = new TreeNode(x);
        }

        TreeNode* newNode = new TreeNode(y);

        if (z == 0) {
            nodes[x]->left = newNode;
        } else {
            nodes[x]->right = newNode;
        }

        nodes[y] = newNode;
    }

    int maxWidth = findMaxWidth(nodes[1]);
    cout << maxWidth << endl;

    return 0;
}

