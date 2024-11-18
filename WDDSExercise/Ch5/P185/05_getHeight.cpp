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


// 求解的是孩子兄弟法转换之前的树的高度
int getHeight(TreeNode* root){
    if(root == nullptr) return 0;
    return getHeight(root->left)+1 > getHeight(root->right) ? getHeight(root->left)+1 : getHeight(root->right);
}   

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(4);
    cout << getHeight(root) << endl;
    return	0;
}