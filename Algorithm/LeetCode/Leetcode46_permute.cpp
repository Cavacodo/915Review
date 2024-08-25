//全排列
//注意和组合不同的地方在于起始位置
#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>> ans;
deque<int> dq;
void dfs(vector<int> nums,vector<int> &used){
    if(dq.size() == nums.size()) ans.push_back(vector<int>(dq.begin(),dq.end()));
    else{
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            else{
                dq.push_back(nums[i]);
                used[i] = 1;
                dfs(nums,used);
                used[i] = 0;
                dq.pop_back();
            }
        }
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        dfs(nums,used);
        return ans;
    }
};

int main()
{
    
    
    return	0;
}