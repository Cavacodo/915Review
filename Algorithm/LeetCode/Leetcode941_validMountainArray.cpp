//https://leetcode.cn/problems/valid-mountain-array/
#include <bits/stdc++.h>
using namespace std;
// 双指针
// 追求O(n)的时间复杂度
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size()-1;
        while(l < r){
            while(l < r && arr[l+1] > arr[l]) l++;
            while(r > l && arr[r-1] > arr[r]) r--;
            if(l == r && l ^ 0 && r ^ arr.size()-1) return 1;
            return 0;
        }
        return 0;
    }
};

int main()
{
    
    
    return	0;
}