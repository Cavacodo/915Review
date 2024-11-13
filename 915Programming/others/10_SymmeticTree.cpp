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
class Solution {
public:
    bool dfs(TreeNode* t1,TreeNode* t2){
        if((t1 && !t2) || (t2 && !t1)) return false;
        if(!t1 && !t2) return true;
        if(t1->val == t2->val){
            return dfs(t1->left,t2->right) && dfs(t1->right,t2->left);
        }else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return dfs(root->left,root->right);
    }
};

int main()
{
    
    return	0;
}