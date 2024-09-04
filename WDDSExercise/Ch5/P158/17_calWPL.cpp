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

int sum;
void calWPL(TreeNode* root,int l){
    if(!root) return;
    if(!root->left && !root->right){
        sum += root->val * l;
        return;
    }
    else{
        if(root->left){
            calWPL(root->left,l+1);
        }
        if(root->right){
            calWPL(root->right,l+1);
        }
    }
}
int main()
{
    sum = 0;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    calWPL(root,0);
    cout << sum << endl;
    return	0;
}