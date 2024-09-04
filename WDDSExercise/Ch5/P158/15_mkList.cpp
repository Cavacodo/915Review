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
 
vector<TreeNode*> v;
void dfs(TreeNode* root){
    if(root->left == nullptr && root->right == nullptr) v.push_back(root);
    if(root->left) dfs(root->left);
    if(root->right) dfs(root->right);
}
TreeNode* mkList(TreeNode *t){
    dfs(t);
    TreeNode *root = new TreeNode();
    TreeNode *cur = root;
    for(auto &i : v){
        cur->right = i;
        cur = cur->right;
    }
    return root->right;
}

unordered_set<TreeNode*> uset;
TreeNode* findLeaves(TreeNode* root){
    if(!root->left && !root->right) return root;
    TreeNode *l, *r;
    // 之前的野指针就是在没有判断好空，认为一定没有空指针，但也可能出现野指针
    // 非叶子节点没有明确返回值
    if(root->left){
        l = findLeaves(root->left);
        if(l) uset.insert(l);
    }
    if(root->right){
        r = findLeaves(root->right);
        if(r) uset.insert(r);
    }
    return NULL;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    findLeaves(root); // 叶子节点存在uset里了
    TreeNode* ans = mkList(root);
    while(ans){
        cout << ans->val << "\t";
        ans = ans->right;
    }
    cout << endl;
    return	0;
}