// 求兄弟链表发存储的树的二叉树原高度
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

int getHeight(TreeNode* root){
    if(!root) return 0;
    if(root->left > root->right) return getHeight(root->left)+1;
    else return getHeight(root->right); //右兄弟的高度不能再加1，左儿子节点可以加一
}

int main()
{
    
    
    return	0;
}