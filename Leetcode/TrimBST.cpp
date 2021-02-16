#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return root;
    if (root->val > high) return trimBST(root->left, low, high);
    if (root->val < low) return trimBST(root->right, low, high);

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main(int argc, char const *argv[]) {
    TreeNode root = TreeNode(1);
    TreeNode nodeLeft = TreeNode(0);
    TreeNode nodeRight = TreeNode(2);
    root.left = &nodeLeft;
    root.right = &nodeRight;
    TreeNode* trimTree = trimBST(&root, 1, 2);
    return 0;
}
