// Leetcode Oct challenge week 4 Day 3

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

TreeNode* prevNode = nullptr;
TreeNode* firstNode = nullptr;
TreeNode* secondNode = nullptr;

void inOrderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);

    if (prevNode != nullptr && prevNode->val > root->val && firstNode == nullptr) {
        firstNode = prevNode;    
    }  
    
    if (prevNode != nullptr && prevNode->val > root->val && firstNode != nullptr) {
        secondNode = root;
    }

    prevNode = root;
    
    inOrderTraversal(root->right);
}

int main(int argc, char const *argv[]) {

    // Construct a unbalanced BST tree.
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);
    TreeNode node4 = TreeNode(4);

    node3.left = &node1;
    node4.left = &node2;
    node3.right = &node4;
    
    inOrderTraversal(&node3);

    // Swap two nodes vals to recover BST.
    int val = firstNode->val;
    firstNode->val = secondNode->val;
    secondNode->val = val;

    return 0;
}
