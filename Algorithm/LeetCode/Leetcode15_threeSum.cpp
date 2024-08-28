// TODO 双指针的好题，好好看看怎么限制指针移动
// 三指针固定一个指针的移动方向
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int l = 0; l < nums.size(); l++){
            if(nums[l] > 0) break;
            if(l > 0 && nums[l] == nums[l-1]) continue;
            int i = l + 1, r = nums.size() - 1;
            while(i < r){
                int t = nums[l] + nums[r];
                int sum = t + nums[i];
                if(sum == 0){
                    vector<int> tmp;
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[r]);
                    ans.push_back(tmp);
                    while(i < r && nums[i] == nums[i+1]) i++;
                    while(i < r && nums[r] == nums[r-1]) r--;
                    i++;
                    r--;
                }else if(sum < 0){
                    i++;
                }else{
                    r--;
                }
            }
        }
        return ans;

    }
};

int main()
{
    vector<int> a = {-2,1,-1,2};
    Solution sol;
    sol.threeSum(a);
    return	0;
}