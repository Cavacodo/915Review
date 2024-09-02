//判断一棵树是不是BST
//奖励题，太简单了
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

vector<int> v;
void inOrder(TreeNode *root){
    if(!root) return;
    inOrder(root->left);
    v.push_back(root->val);
    inOrder(root->right);
}
bool isBST(TreeNode *root){
    inOrder(root);
    for(int i = 1; i < v.size(); i++) if(v[i] < v[i-1]) return 0;
    return true;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    cout << isBST(root) << endl;
    return	0;
}