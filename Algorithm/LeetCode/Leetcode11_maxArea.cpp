/*
    leetcode 11
    非常好的双指针做法，只需要O(n)时间复杂度
    https://leetcode.cn/submissions/detail/557882072/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r = height.size()-1,mx = 0;
        while(l < r){
            mx = height[l] > height[r] ? max(mx,(r-l)*height[r--]) : max(mx,(r-l)*height[l++]);
        }
        return mx;
    }
};

int main()
{
    Solution s;
    
    return	0;
}