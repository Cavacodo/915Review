//组合总数2 
//注意出现重复元素组合怎么剪枝，重点在start 和 i的关系上
//if(i > 0 && candidates[i] == candidates[i-1] && start != i) continue;
//同一层的相同元素的start相同，但是同一枝不同层的不同
//也可使用used数组（更好理解）

#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>> ans;
deque<int> dq;
void dfs(vector<int> &candidates,int res,int start){
    if(res < 0) return ;
    else if(res == 0){
        ans.push_back(vector<int>(dq.begin(),dq.end()));
    }else{
        for(int i = start; i < candidates.size() && res - candidates[i] >= 0; i++){
            if(i > 0 && candidates[i] == candidates[i-1] && start != i) continue;
            dq.push_back(candidates[i]);
            res -= candidates[i];
            dfs(candidates,res,i+1);
            res += candidates[i];
            dq.pop_back();
        }
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return ans;
    }
};

//使用used进行剪枝
//重点在if(i>0 && candidates[i-1] == candidates[i] && !used[i-1]) continue;
//同一层的used[i-1]是0，同一枝的则是1
class Solution2 {
deque<int> dq;
vector<vector<int>> ans;
void dfs(vector<int> &candidates,int res,int start,vector<bool> &used){
    if(res < 0) return;
    else if(res == 0){
        ans.push_back(vector<int>(dq.begin(),dq.end()));
    }else{
        for(int i = start; i < candidates.size() && res - candidates[i] >= 0; i++){
            if(i>0 && candidates[i-1] == candidates[i] && !used[i-1]) continue;
            dq.push_back(candidates[i]);
            res -= candidates[i];
            used[i] = 1;
            dfs(candidates,res,i+1,used);
            used[i] = 0;
            res += candidates[i];
            dq.pop_back();
        }
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(),0);
        dfs(candidates,target,0,used);
        return ans;
    }
};

int main()
{
    
    
    return	0;
}