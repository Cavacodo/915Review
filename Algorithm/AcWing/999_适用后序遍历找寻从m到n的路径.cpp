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

// 叫postorder仅仅是因为在if判断时将树遍历完了
bool postOrder(TreeNode* root,TreeNode* n){
    if(!root) return false;
    if(root == n || postOrder(root->left,n) || postOrder(root->right,n)){
        cout << root->val << '\t';
        return true;
    }
    return false;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    TreeNode* n = root->left->right;
    postOrder(root,n);
    cout << endl;
    return	0;
}