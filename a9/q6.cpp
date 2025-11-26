#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int postIndex;

TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
    if (inStart > inEnd) return nullptr;
    int rootVal = postorder[postIndex--];
    TreeNode* root = new TreeNode(rootVal);
    int inIndex = inMap[rootVal];
    root->right = buildTreeInPost(inorder, postorder, inIndex+1, inEnd, inMap);
    root->left = buildTreeInPost(inorder, postorder, inStart, inIndex - 1, inMap);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> inMap;
    for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    postIndex = postorder.size() - 1;
    return buildTreeInPost(inorder, postorder, 0, inorder.size() - 1, inMap);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
    printInorder(root);
    cout << endl;
    return 0;
}
