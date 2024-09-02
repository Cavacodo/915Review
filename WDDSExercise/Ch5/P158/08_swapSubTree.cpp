// 交换所有子树
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

void swap(TreeNode *root){
    if(root == nullptr) return;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    swap(root->left);
    swap(root->right);
}

void LevelOrder(TreeNode *t){
    deque<TreeNode*> dq;
    dq.push_back(t);
    while(!dq.empty()){
        int size = dq.size();
        while(size--){
            TreeNode *tmp = dq.front();
            dq.pop_front();
            if(tmp->left != nullptr) dq.push_back(tmp->left);
            if(tmp->right != nullptr) dq.push_back(tmp->right);
            cout << tmp->val << "\t";
        }
        cout << endl;
    }
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    LevelOrder(root);
    swap(root);
    LevelOrder(root);
    return	0;
}