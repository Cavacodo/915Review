// https://leetcode.cn/problems/combination-sum-iii/description/
// 使用res或者使用sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
vector<vector<int>> ans;
deque<int> dq;
void dfs(int k,int res,int start){
    if(dq.size() == k){
        if(res != 0) return;
        else{
            ans.push_back(vector<int>(dq.begin(),dq.end()));
        }
    }else{
        for(int i = start; i <= 9-(k-dq.size())+1; i++){
            if(res - i >= 0){
                res -= i;
                dq.push_back(i);
                dfs(k,res,i+1);
                res += i;
                dq.pop_back();
            }
        }
    }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n,1);
        return ans;
    }
};

int main()
{
    
    
    return	0;
}