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
void findParent(TreeNode* root,TreeNode* k){
    deque<TreeNode*> dq;
    dq.push_back(root);
    v.push_back(root);
    while(!dq.empty()){
        int size = dq.size();
        for(int i = 0; i < size; i++){
            TreeNode* tmp = dq.front();
            dq.pop_front();
            if(tmp->left){
                v.push_back(tmp->left);
                dq.push_back(tmp->left);
            }else{
                v.push_back(new TreeNode(-1));
            }
            if(tmp->right){
                dq.push_back(tmp->right);
                v.push_back(tmp->right);
            }else{
                v.push_back(tmp->right);
            }
        }
    }
    for(int i = 1; i < v.size(); i++){
        if(v[i] == k) cout << v[i/2]->val << endl;
    }
}
int main()
{
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->right->left = new TreeNode(5);
    TreeNode* occ = new TreeNode(-1);
    v.push_back(occ);
    findParent(t,t->left->left);
    return	0;
}