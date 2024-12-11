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

vector<vector<int>> ans;
vector<int> t;
void dfs(TreeNode* root,int res){
    if(!root) return ;
    t.push_back(root->val);
    res -= root->val;
    if(!root->left && !root->right && !res) ans.push_back(t);
    dfs(root->left,res);
    dfs(root->right,res);
    t.pop_back();
}

int main()
{
    TreeNode* head = new TreeNode(10);
    head->left = new TreeNode(5);
    head->right = new TreeNode(12);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(7);
    dfs(head,22);
    return	0;
}