// TODO 差分
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i],dp[i-1] + nums[i]);
        }
        int ans = INT_MIN;
        for(int i : dp) ans = max(ans,i);
        return ans;
    }
};

int main()
{
    
    return	0;
}