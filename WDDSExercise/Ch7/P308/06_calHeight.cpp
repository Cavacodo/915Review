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

int getHeight(TreeNode* root,int x,int h){
    if(root->val == x) return h;
    if(root->left && root->right){
        int l = getHeight(root->left,x,h+1);
        int r = getHeight(root->right,x,h+1);
        if(l) return l;
        if(r) return r;
    }
    if(root->left) return getHeight(root->left,x,h+1);
    if(root->right) return getHeight(root->right,x,h+1);
    return 0; //没找到
}
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << getHeight(root,3,1) << endl; 
    return	0;
}