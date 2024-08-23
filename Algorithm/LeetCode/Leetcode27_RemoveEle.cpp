// 删除元素
// https://leetcode.cn/problems/remove-element/

#include "bits/stdc++.h"
using namespace std;

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

int main(){
    vector<int> nums = {1,3,4,5,3,7};
    int b[] = {1,2,43,8};
    sort(nums.begin(),nums.end());
    cout << 1 << endl;
}