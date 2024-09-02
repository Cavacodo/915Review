// 统计所有分支为2的节点的个数
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

int getBinaryBranch(TreeNode* root,int sum){
    if(root == nullptr) return 0;
    if(root->left && root->right) return getBinaryBranch(root->left,sum) + getBinaryBranch(root->right,sum) + 1;
    else if(root->left == nullptr) return getBinaryBranch(root->right,sum);
    else return getBinaryBranch(root->left,sum);
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    cout << getBinaryBranch(root,0) << endl;
    return	0;
}