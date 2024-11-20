// leetcode102
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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int level){
        if(root == nullptr) return ;
        if(ans.size() <= level){
            vector<int> v;
            ans.push_back(v);
        }
        ans[level].push_back(root->val);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};

int main()
{
    
    return	0;
}