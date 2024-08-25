// 组合总和
// 注意难点在剪枝操作
#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>> ans;
deque<int> dq;
void dfs(vector<int> &candidates,int res,int start){
    if(res == 0) ans.push_back(vector<int>(dq.begin(),dq.end()));
    else if(res < 0) return;
    else{
        for(int i = start; i < candidates.size(); i++){
            dq.push_back(candidates[i]);
            res -= candidates[i];
            dfs(candidates,res,i);
            res += candidates[i];
            dq.pop_back();
        }
    }
}
//剪枝操作
//先对candidate进行sort排序，然后再for循环中添加res - candidates[i] >= 0（必须先排序，不然会漏情况，因为直接跳过了后面元素的遍历）
class Solution2 {
vector<vector<int>> ans;
deque<int> dq;
void dfs(vector<int> &candidates,int res,int start){
    if(res == 0) ans.push_back(vector<int>(dq.begin(),dq.end()));
    else if(res < 0) return;
    else{
        for(int i = start; i < candidates.size() && res - candidates[i] >= 0; i++){
            dq.push_back(candidates[i]);
            res -= candidates[i];
            dfs(candidates,res,i);
            res += candidates[i];
            dq.pop_back();
        }
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return ans;
    }
};
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0);
        return ans;
    }
};

int main()
{
    
    
    return	0;
}