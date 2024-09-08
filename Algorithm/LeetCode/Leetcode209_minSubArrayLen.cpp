// 滑动窗口 + 差分
// 二分差分O(nlog(n))超时
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = INT_MAX;
        int sum = 0;
        while(r < n){
            sum += nums[r];
            if(sum < target){
                r++;
                continue;
            }
            while(sum >= target){
                ans = min(ans,r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    
    
    return	0;
}