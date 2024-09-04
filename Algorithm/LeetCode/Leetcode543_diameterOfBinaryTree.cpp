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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TODO 有意义的题，对递归边界的判断 
class Solution {
public:
    int dfs(TreeNode* root,int &h){
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int l = 0, r = 0;
        if(root->left) l = dfs(root->left,h) + 1;
        if(root->right) r = dfs(root->right,h) + 1;
        h = max(h,l+r);
        return max(l,r);    //只返回最大层高，不管计算
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        if(!root) return 0;
        dfs(root,h);
        return h;
    }
};

int main()
{
    
    
    return	0;
}