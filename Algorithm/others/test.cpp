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

int fun(int n){
    if(n == 0) return 0;
    return fun(n/10)*10+n%10;
}

void preIn(TreeNode* root){
    if(!root) return ;
    cout << root->val << endl;
    preIn(root->left);
    cout << root->val << endl;
    preIn(root->right);
    cout << root->val << endl;
}

int main()
{
    TreeNode* head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(3);
    preIn(head);
    cout << fun(1234) << endl;
    return	0;
}