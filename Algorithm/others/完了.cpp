#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preIn(TreeNode* root){
    if(!root) return ;
    cout << root->val << endl;
    preIn(root->left);
    cout << root->val << endl;
    preIn(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->left->left = new TreeNode(1);
    root->right->left->left->right = new TreeNode(9);
    root->right->left->right = new TreeNode(6);
    preIn(root);
    return	0;
}