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

int dfs(TreeNode* head,TreeNode* p){
    if(!head) return 0;
    if(head == p) return 1;
    // 这里不是判断大小的，是判断是不是0的
    return 1 + max(dfs(head->left,p),dfs(head->right,p));
}
int main()
{
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right =  new TreeNode(3);
    head->left->left = new TreeNode(4);
    cout << dfs(head,head->left->left) << endl;
    return	0;
}