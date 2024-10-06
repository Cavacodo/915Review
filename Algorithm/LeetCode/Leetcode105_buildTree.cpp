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
    vector<int> in;
    vector<int> post;
    unordered_map<int,int> umap;
    int len;
    // 左闭右开
    TreeNode* dfs(int pl,int pr,int il,int ir){
        if(pl == pr || pr <= 0) return nullptr;
        // 右子树长度
        int offset = ir - umap[post[pr-1]] - 1;
        TreeNode* right = dfs(pr-offset-1,pr-1,ir-offset-1,ir-1);
        TreeNode* left = dfs(pl,pr-offset-1,il,ir-offset-1);
        return new TreeNode(post[pr-1],left,right);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder,post = postorder;
        len = inorder.size();
        for(int i = 0; i < len; i++) umap[inorder[i]] = i;
        return dfs(0,len,0,len);
    }
};
int main()
{
    
}