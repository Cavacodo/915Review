#include <bits/stdc++.h>
using namespace std;
// 按照0，1，2的顺序排好的话直接sort就行了
// 现在使用双指针
// 使用额外空间将会变的无比简单
// 考虑双指针(看似双指针，其实用了三个指针指示位置)
// TODO 双指针经典题
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

int main()
{
    
    
    return	0;
}