// 是否是完全二叉树
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

int getHeight(TreeNode* root){
    if(!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
bool isCompleteTree(TreeNode* root){
    int height = getHeight(root);
    vector<deque<TreeNode*>> v;
    deque<TreeNode*> dq;
    dq.push_back(root);
    while(!dq.empty()){
        int size = dq.size();
        deque<TreeNode*> tq;
        for(int i = 0; i < size; i++){
            TreeNode* node = dq.front();
            dq.pop_front();
            tq.push_back(node);
            if(node->left) dq.push_back(node->left);
            if(node->right) dq.push_back(node->right);
        }
        v.push_back(tq);
    }
    int cnt = 0;
    for(int i = 0; i < v.size()-1; i++){
        deque<TreeNode*> tmp = v[i];
        if(tmp.size() != pow(2.0,cnt++)) return false;
    }
    deque<TreeNode*> t = v[v.size()-2];
    int n = v[v.size()-1].size();
    int q = 0;
    for(auto &o : t){
        if(o->left && o->right) q+=2;
        else if(o->left) q++;
        else if(o->right) return false;
        else{
            return q == n;
        }
    }
    return 1;
}

bool isCompleteTree_concise(TreeNode *root){
    vector<int> v;
    deque<TreeNode*> dq;
    dq.push_back(root);
    while(!dq.empty()){
        TreeNode *t = dq.front();
        dq.pop_front();
        if(t == nullptr){
            v.push_back(-1);
            continue;
        }
        v.push_back(t->val);
        if(t->left) dq.push_back(t->left);
        else dq.push_back(nullptr);
        if(t->right) dq.push_back(t->right);
        else dq.push_back(nullptr);
    }
    bool flag = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == -1) flag = 1;
        if(flag && v[i] > 0) return false; 
    }
    return true;
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
    cout << isCompleteTree_concise(root) << endl;
    return	0;
}