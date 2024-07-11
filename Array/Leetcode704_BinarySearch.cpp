//  二分查找模版
//  https://leetcode.cn/problems/binary-search/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l,r;
        r = nums.size() - 1;
        l = 0;
        int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return -1; 
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 6;
    int ans = sol.search(nums,target);
    cout << ans << endl;
    
}