// 求二叉树树高 非递归算法
#include <bits/stdc++.h>
using namespace std;


// 二叉树好定义
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
int getTreeHeight(TreeNode* root)
{
    if(root == nullptr) return 0;
    return max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
}

int getTreeHeight_non_recursive(TreeNode* root){
    int ans = 0;
    deque<TreeNode*> dq;
    dq.push_back(root);
    while(!dq.empty()){
        int size = dq.size();
        ans++;
        for(int i = 0; i < size; i++){
            TreeNode *tmp = dq.front();
            dq.pop_front();
            if(tmp->left) dq.push_back(tmp->left);
            if(tmp->right) dq.push_back(tmp->right);
        }
    }
    return ans;
}

int main()
{
    //生成一棵二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << getTreeHeight(root) << endl;
    cout << getTreeHeight_non_recursive(root) << endl;
    return	0;
}