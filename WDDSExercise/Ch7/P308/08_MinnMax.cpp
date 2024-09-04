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

int mn = INT_MAX,mx = INT_MIN;
void getMin(TreeNode* root){
    if(!root->left) mn = min(mn,root->val);
    if(root->left) getMin(root->left);
}
void getMax(TreeNode* root){
    if(!root->right) mx = max(mx,root->val);
    if(root->right) getMax(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    getMin(root);
    getMax(root);
    cout << mn << "\t" << mx << endl;
    return	0;
}