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

int ans = 0;
int dfs(TreeNode* root,TreeNode* k){
    if(k == root) return 1;
    if(root->left)  return dfs(root->left,k);
    if(root->right) return dfs(root->right,k);
    return 0;
}
int getAns(TreeNode* head,TreeNode* k){
    if(dfs(head,k)) ans += dfs(head,k);
    return ans;
}
int main()
{
    TreeNode* head = new TreeNode(0);
    head->left = new TreeNode(1);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->left->left = new TreeNode(4);
    cout << getAns(head,head->left->left->left) << endl;
    return	0;
}