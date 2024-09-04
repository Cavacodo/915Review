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
    TreeNode* dfs(vector<int>& nums,int l,int r){
        int mid = (l + r + 1) / 2;
        if(r == l) return new TreeNode(nums[l]);
        TreeNode* m = new TreeNode(nums[mid]);
        if(mid-1 >= l) m->left = dfs(nums,l,mid-1);
        if(mid+1 <= r) m->right = dfs(nums,mid+1,r);
        return m;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};
int main()
{
    
    
    return	0;
}