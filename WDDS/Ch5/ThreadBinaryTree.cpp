#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int ltag = 0;
    int rtag = 0;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}ThreadNode;

// inorder init
void InThread(ThreadNode *p,ThreadNode *pre){
    if(p){
        InThread(p->left,pre);
        if(!p->left){
            p->left = pre;
            p->ltag = 1;
        }
        if(pre && !pre->right){
            pre->right = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->right,pre);
    }
}

void CreateInThread(ThreadNode *root){
    ThreadNode *pre = nullptr;
    if(root){
        InThread(root,pre);
        pre->right = nullptr;
        pre->rtag = 1;
    }
}
int main()
{
    ThreadNode* root = new ThreadNode(1);
    root->left = new ThreadNode(2);
    root->left->left = new ThreadNode(3);
    root->left->right = new ThreadNode(4);
    root->right = new ThreadNode(5);
    CreateInThread(root);
    return	0;
}