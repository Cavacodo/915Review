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

class Solution {
public:
    vector<int> v;
    void dfs(TreeNode* root,int h){
        if(!root) return;
        if(h == v.size()) v.push_back(root->val);
        dfs(root->right,h+1);
        dfs(root->left,h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return v;
    }
};
int main()
{
    
    
    return	0;
}