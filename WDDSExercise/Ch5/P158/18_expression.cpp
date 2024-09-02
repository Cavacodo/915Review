// 挺有意思的中缀表达式
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_set<char> uset;
TreeNode *r;
void midExpression(TreeNode* root){
    if(!root) return;
    if(uset.count(root->val) && root != r){
        cout << '(';
        midExpression(root->left);
        cout << root->val;
        midExpression(root->right);
        cout << ')';
    }else{
        midExpression(root->left);
        cout << root->val;
        midExpression(root->right);
    }
}
int main()
{
    uset.insert('*');
    uset.insert('/');
    uset.insert('-');
    uset.insert('+');
    TreeNode* root = new TreeNode('+');
    r = root;
    root->left = new TreeNode('*');
    root->right = new TreeNode('-');
    root->left->left = new TreeNode('a');
    root->left->right = new TreeNode('b');
    root->right->right = new TreeNode('-');
    root->right->right->right = new TreeNode('d');
    root->right->right->left = new TreeNode('c');
    midExpression(root);
    cout << endl;
    return	0;
}