// DP 0-1背包解法
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = reduce(nums.begin(),nums.end());
        if(sum % 2) return 0;
        vector<int> dp(sum/2+1,0);  //  dp存的是每个地方能到达的最大大小
        for(int i = 0; i < nums.size(); i++){
            for(int j = sum/2; j >= nums[i]; j--){
                // 每次选择一个元素能到哪里的所有集合
                dp[j] = max(dp[j],dp[j-nums[i]] + nums[i]);
            }
        }
        return dp[sum/2] == sum/2;
    }
};
// 二维数组版本 保存的是选了的和没选的情况，把所有元素都筛了一遍
class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = reduce(nums.begin(),nums.end());
        if(sum % 2) return 0;
        // DP存的是每个地方能否到达
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,0));
        dp[0][0] = 1;   // 不选肯定能到达
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 0; j <= sum/2; j++){
                // 不循环到nums[i-1]而是所有筛选一遍是为了把上面的数据都保存下来
                if(j < nums[i-1]){  //上一个都不能选
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i-1]]);
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};

int main()
{
    
    
    return	0;
}