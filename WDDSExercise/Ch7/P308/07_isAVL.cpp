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
int dfs(TreeNode* root){
    if(!root) return 0;
    return max(dfs(root->left),dfs(root->right))+1;
}
bool isAVL(TreeNode* root){
    if(!root) return true;
    if(root->left && root->right) return dfs(root->left) == dfs(root->right);
    if(root->left) return dfs(root->left) == 1;
    if(root->right) return dfs(root->right) == 1;
    return false;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    cout << isAVL(root) << endl;
    return	0;
}