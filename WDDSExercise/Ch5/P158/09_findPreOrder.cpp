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

int cnt = 0;

void preOrder(TreeNode* root,int k){
    cnt++;
    if(cnt == k){
        cout << 'N' << root->val <<  endl;
        return;
    }
    cout << root->val << '\t' << cnt << endl;
    if(root->left) preOrder(root->left,k);
    if(root->right) preOrder(root->right,k);
}

int main()
{
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    preOrder(head,4);
    return	0;
}