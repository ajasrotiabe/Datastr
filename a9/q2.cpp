#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateTreesUtil(int start, int end) {
    vector<TreeNode*> res;
    if (start > end) {
        res.push_back(nullptr);
        return res;
    }
    for (int i = start; i <= end; i++) {
        auto leftTrees = generateTreesUtil(start, i - 1);
        auto rightTrees = generateTreesUtil(i + 1, end);
        for (auto l : leftTrees) {
            for (auto r : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesUtil(1, n);
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int n = 3;
    auto trees = generateTrees(n);
    for (auto t : trees) {
        printTree(t);
        cout << endl;
    }
    return 0;
}
