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
int deg_one = 0, deg_two = 0, deg_zero = 0;

void calDeg(TreeNode* root){
    if(root == nullptr) return ;
    if(!root->left && !root->right){
        deg_zero++;
        return ;
    }
    if((root->left && !root->right) || (root->right && !root->left)) deg_one++;
    if(root->left && root->right) deg_two++;
    if(root->left) calDeg(root->left);
    if(root->right) calDeg(root->right);
}

int calHeight(TreeNode* head){
    if(head == nullptr) return 0;
    return max(calHeight(head->left),calHeight(head->right))+1;
}

int calBreadth(TreeNode* head){
    
}

int main()
{
    TreeNode* root = new TreeNode();
    root->left = new TreeNode();
    root->right = new TreeNode();
    root->left->left = new TreeNode();
    calDeg(root);
    cout << calHeight(root) << endl;
    return	0;
}