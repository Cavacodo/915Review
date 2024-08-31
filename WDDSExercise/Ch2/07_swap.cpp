/* 题目描述：在一维有序数组中依次存放两个线性表(a1,a2,...,am) (b1,b2,...,bn)
 * 在不使用额外空间的前提下，把所有b数组移动到a前
 * 并且保证书序不变
 */
#include <bits/stdc++.h>
using namespace std;

// 三次交换的魅力
void swap_array(vector<int> &nums,int m,int n){
    for(int i = 0; i < nums.size() / 2; i++) swap(nums[i],nums[m+n-1-i]);
    for(int i = 0; i < n/2; i++) swap(nums[i],nums[n-1-i]);
    for(int i = n; i < n + m/2; i++) swap(nums[i],nums[m+n-1-(i-n)]);
}

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,-1,-2,-3};
    int m = 8, n = 3;
    swap_array(nums,m,n);
    for(auto &a : nums) cout << a << "\t";
    cout << endl;
    return	0;
}