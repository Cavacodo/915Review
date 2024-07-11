/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int a = 0x3f3f3f3f;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                nums[i] = a;
                cnt++;
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size() - cnt;
    }
};
// @lc code=end

