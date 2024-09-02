// 删除对应值为节点的子树
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

// d = 0左 1右
void removeTree(TreeNode* root,TreeNode* predecessor,int val,int d){
    if(root == nullptr) return;
    if(root->val == val && d == 0) predecessor->left = nullptr;
    if(root->val == val && d == 1) predecessor->right = nullptr;
    removeTree(root->left,root,val,0);
    removeTree(root->right,root,val,1);
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
    removeTree(root,nullptr,3,0);
    removeTree(root,nullptr,3,1);
    LevelOrder(root);
    return	0;
}