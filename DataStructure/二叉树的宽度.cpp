// leetcode 662
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,long long> umap;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        umap[root] = 1;
        long long ans = 1;
        while(!dq.empty()){
            int size = dq.size();
            long long first = -1,last = -1;
            for(int i = 0; i < size; i++){
                if(dq[i]->left || dq[i]->right){
                    if(dq[i]->left){
                        first = umap[dq[i]] * 2;
                        break;
                    }
                    else if(dq[i]->right){
                        first = umap[dq[i]] * 2 + 1;
                        break;
                    }
                }
            }
            for(int i = size-1; i>=0; i--){
                if(dq[i]->left || dq[i]->right){
                    if(dq[i]->right){
                        last = umap[dq[i]] * 2 + 1;
                        break;
                    }
                    else if(dq[i]->left){
                        last = umap[dq[i]] * 2;
                        break;
                    }
                }
            }
            for(int i = 0; i < size; i++){
                TreeNode* t = dq.front();
                dq.pop_front();
                if(t->left){
                    umap[t->left] = umap[t] * 2 - first + 1;
                    dq.push_back(t->left);
                }
                if(t->right){
                    umap[t->right] = umap[t] * 2 - first + 2;
                    dq.push_back(t->right);
                }
            }
            ans = max(ans,last - first + 1);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(3);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(5);
    head->left->right = new TreeNode(3);
    head->right->right = new TreeNode(9);
    sol.widthOfBinaryTree(head);
    return	0;
}
