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

bool isResemble(TreeNode* t1, TreeNode* t2){
    if(!t1 && !t2) return true;
    if(!t1->right && !t1->left && !t2->left && !t2->right) return true;
    if((t1->right && !t2->right) || (!t1->right && t2->right)) return false;
    if((!t1->right && t2->right) || (t1->right && !t2->right)) return false;
    return isResemble(t1->left,t2->left) && isResemble(t1->right,t2->right);
}

int main()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    t2->left = new TreeNode(5);
    t2->right = new TreeNode(6);
    cout << isResemble(t1,t2) << endl;
    return	0;
}