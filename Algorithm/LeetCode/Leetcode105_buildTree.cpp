#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> pre;
    vector<int> in;
    unordered_map<int,int> map;
    TreeNode* dfs(int pl,int pr,int il,int ir){
        if(pl == pr) return nullptr;
        int offset = map[pre[pl]] - il;
        //  左闭右开区间
        TreeNode* left = dfs(pl+1,pl+1+offset,il,il+offset);
        TreeNode* right = dfs(pl+1+offset,pr,il+offset+1,ir);
        return new TreeNode(pre[pl],left,right);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder,in = inorder;
        for(int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        int n = preorder.size();
        return dfs(0,n,0,n);
    }
};
int main()
{
    
}