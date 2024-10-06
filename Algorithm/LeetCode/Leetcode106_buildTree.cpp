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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) { // 空节点
            return nullptr;
        }
        int left_size = ranges::find(inorder, postorder.back()) - inorder.begin(); // 左子树的大小
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + left_size + 1, inorder.end());
        vector<int> post1(postorder.begin(), postorder.begin() + left_size);
        vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);
        TreeNode *left = buildTree(in1, post1);
        TreeNode *right = buildTree(in2, post2);
        return new TreeNode(postorder.back(), left, right);
    }
};



class Solution2 {
public:
    vector<int> in;
    vector<int> post;
    unordered_map<int,int> umap;
    TreeNode* dfs(int pl,int pr,int il,int ir){
        if(pl == pr) return nullptr;
        int left_size = umap[post[pr-1]] - il;
        TreeNode* left = dfs(pl,pl+left_size,il,il+left_size);
        TreeNode* right = dfs(pl+left_size,pr-1,il+left_size+1,ir);
        return new TreeNode(post[pr-1],left,right); 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        in = inorder;
        post = postorder;
        for(int i = 0 ; i < postorder.size(); i++) umap[inorder[i]] = i;
        return dfs(0,n,0,n);
    }
};

int main()
{
    vector<int> post = {9,15,7,20,3};
    vector<int> in = {9,3,15,20,7};
    Solution sol;
    sol.buildTree(in,post);
    return	0;
}