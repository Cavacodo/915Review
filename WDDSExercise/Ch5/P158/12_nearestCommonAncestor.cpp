// 求两个节点的最近祖先
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

deque<TreeNode*> s1;
deque<TreeNode*> s2;
void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return;
        dfs(root->left,p,q);
        dfs(root->right,p,q);
        if(s1.front() == (root->left) || s1.front() == (root->right)){
            s1.push_front(root);
        }
        if(s2.front() == (root->left) || s2.front() == (root->right)){
            s2.push_front(root);
        }
    }
TreeNode* nearestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode *q){
    s1.push_front(p);
    s2.push_front(q);
    dfs(root,p,q);
    unordered_set<TreeNode*> set;
    for(auto &i : s1) set.insert(i);
    for(int i = s2.size()-1; i >= 0; i--){
        if(set.count(s2[i])) return s2[i];
    }
    return root;
}
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    cout << nearestCommonAncestor(root,root->left,root->left->right->right)->val <<endl;
    return	0;
}