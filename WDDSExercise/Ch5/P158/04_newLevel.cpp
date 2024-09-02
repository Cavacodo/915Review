// 编写二叉树从下而上，从右向左的层次遍历
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

void newLevel(TreeNode* root){
    deque<TreeNode*> dq;
    vector<deque<TreeNode*>> v;
    dq.push_back(root);
    while(!dq.empty()){
        int size = dq.size();
        deque<TreeNode*> tq;
        while(size--){
            TreeNode *tmp = dq.front();
            dq.pop_front();
            tq.push_back(tmp);
            if(tmp->left) dq.push_back(tmp->left);
            if(tmp->right) dq.push_back(tmp->right);
        }
        v.push_back(tq);
    }
    for(int i = v.size() - 1; i >= 0; i--){
        for(int j = v[i].size(); j > 0; j--){
            cout << v[i].back()->val << "\t";
            v[i].pop_back();
        }
        cout << endl;
    }
}
int main()
{
    //生成一棵树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    newLevel(root);
    
    return	0;
}