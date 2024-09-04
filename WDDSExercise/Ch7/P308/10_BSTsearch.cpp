// 这题比较好，分支条件的划分
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int cnt;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), cnt(0), left(nullptr), right(nullptr) {}
    TreeNode(int x,int cnt) : val(x), cnt(cnt), left(nullptr), right(nullptr) {}
    TreeNode(int x, int cnt, TreeNode *left, TreeNode *right) : val(x), cnt(cnt), left(left), right(right) {}
};

TreeNode* BSTsearch(TreeNode* root,int k){
    if(k < 1 || k > root->cnt) return nullptr;
    if(!root->left){
        if(k == 1) return root;
        else return BSTsearch(root->right,k-1);
    }else{
        if(root->left->cnt == k-1) return root;
        if(root->left->cnt > k-1) return BSTsearch(root->left,k);
        else return BSTsearch(root->right,k-(root->left->cnt+1));
    }
}
int main()
{
    TreeNode* root = new TreeNode(4,5);
    root->left = new TreeNode(2,3);
    root->left->left = new TreeNode(1,1);
    root->left->right = new TreeNode(3,1);
    root->right = new TreeNode(5,1);
    TreeNode* ans = BSTsearch(root,5);
    cout << ans->val << endl;
    return	0;
}