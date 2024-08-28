// 层序遍历
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
//DFS也挺有意思，维护着res，保存不同层的最大元素
class Solution1 {
public:
    void dfs(vector<int>& res, TreeNode* root, int curHeight) {
        if (curHeight == res.size()) {  //第一次这一层的元素
            res.push_back(root->val);
        } else {
            //后面的更新这个最大值
            res[curHeight] = max(res[curHeight], root->val);
        }
        if (root->left) {
            dfs(res, root->left, curHeight + 1);
        }
        if (root->right) {
            dfs(res, root->right, curHeight + 1);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }
};


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        deque<TreeNode*> dq;
        if(root == nullptr) return ans;
        dq.push_back(root);
        while(!dq.empty()){
            int size = dq.size();
            int mx = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode* t = dq.front();
                dq.pop_front();
                mx = max(mx,t->val);
                if(t->left != nullptr) dq.push_back(t->left);
                if(t->right != nullptr) dq.push_back(t->right);
            }
            ans.push_back(mx);
        }  
        return ans;
    }
};
int main()
{
    
    
    return	0;
}