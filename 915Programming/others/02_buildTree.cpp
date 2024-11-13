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
void create_Tree(TreeNode* root){
    cout << "输入节点的值" << endl;
    int a;
    cin >> a;
    if(a == -1) return;
    root->val = a;
    root->left = new TreeNode();
    root->right = new TreeNode();
    create_Tree(root->left);
    create_Tree(root->right);
}
int main()
{
    TreeNode* r = new TreeNode();
    create_Tree(r);
    return	0;
}