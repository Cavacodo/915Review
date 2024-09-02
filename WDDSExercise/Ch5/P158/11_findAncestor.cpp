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

void findAncestor(TreeNode *root,int val){
    vector<int> v;
    v.push_back(-1);
    deque<TreeNode*> dq;
    dq.push_back(root);
    int idx = 0;
    while(!dq.empty()){
        TreeNode *tmp = dq.front();
        dq.pop_front();
        if(tmp) v.push_back(tmp->val);
        else{
            v.push_back(0);
            continue;
        }
        if(tmp->val == val) idx = v.size() - 1;
        dq.push_back(tmp->left);
        dq.push_back(tmp->right);
    }
    while(idx > 0){
        cout << v[idx] << "\t";
        idx /= 2;
    }
    cout << endl;
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
    findAncestor(root,7);
    return	0;
}