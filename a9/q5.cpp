#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int preIndex = 0;

TreeNode* buildTreePreIn(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
    if (inStart > inEnd) return nullptr;
    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);
    int inIndex = inMap[rootVal];
    root->left = buildTreePreIn(preorder, inorder, inStart, inIndex - 1, inMap);
    root->right = buildTreePreIn(preorder, inorder, inIndex + 1, inEnd, inMap);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> inMap; 
    for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    preIndex = 0;
    return buildTreePreIn(preorder, inorder, 0, inorder.size() - 1, inMap);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorder, inorder);
    printInorder(root);
    cout << endl;
    return 0;
}
