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

class Solution {
public:
    //dfs算法是用来计算每个节点有多少条符合条件的路径
    int dfs(TreeNode* root,long long res){
        if(!root) return 0;
        long long ret = 0;
        if(root->val == res) ret++;
        ret += dfs(root->left,res-root->val);
        ret += dfs(root->right,res-root->val);
        return ret;
    }
    // 对每个节点遍历一遍
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        long long ret = dfs(root,targetSum);
        ret += pathSum(root->left,targetSum);
        ret += pathSum(root->right,targetSum);
        return ret;
    }
};
int main()
{
    
    
    return	0;
}