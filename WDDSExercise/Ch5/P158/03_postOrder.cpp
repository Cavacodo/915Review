// 后序遍历的非递归算法
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

 void postOrder_non_recursive(TreeNode *root){
    stack<TreeNode*> stack;
    TreeNode *predecessor = nullptr;
    while(root != nullptr || !stack.empty()){
        if(root != nullptr){
            stack.push(root);
            root = root->left;
        }else{
            root = stack.top();
            if(root->right != nullptr && root->right != predecessor){
                root = root->right;
                stack.push(root);
                root = root->left;
            }else{
                stack.pop();
                cout << root->val << " ";
                predecessor = root;
                root = nullptr;
            }
        }
    }
    cout << endl;
 }

int main()
{
    //根据我给的结构体生成一棵树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    postOrder_non_recursive(root);
    return	0;
}