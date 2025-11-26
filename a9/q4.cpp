#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void rightViewUtil(TreeNode* root, int level, int& maxLevel, vector<int>& view) {
    if (!root) return;
    if (level > maxLevel) {
        view.push_back(root->val);
        maxLevel = level;
    }
    rightViewUtil(root->right, level + 1, maxLevel, view);
    rightViewUtil(root->left, level + 1, maxLevel, view);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> view;
    int maxLevel = 0;
    rightViewUtil(root, 1, maxLevel, view);
    return view;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    auto view = rightSideView(root);
    for (int v : view) cout << v << " ";
    cout << endl;
    return 0;
}
