#include <bits/stdc++.h>
using namespace std;
//从大到小输出大于k的数字
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printVal(TreeNode* root,int k){
    if(!root) return;
    printVal(root->right,k);
    if(root->val > k) cout << root->val << "\t";
    printVal(root->left,k);
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    printVal(root,2);
    cout << endl;
    return	0;
}