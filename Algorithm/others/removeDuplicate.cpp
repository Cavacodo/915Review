/*
    删除一个有序数组的重复元素
    Input : [1,2,3,3,4,5,6]
    Output : [1,2,3,4,5,6]
*/
#include <bits/stdc++.h>
using namespace std;
int removeDuplicate(vector<int> &nums){
    int cnt = 0;
    for(auto &n : nums){
        if(!cnt || n > nums[cnt - 1]) nums[cnt++] = n;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,5,6};
    int n = removeDuplicate(nums);
    for(auto i : nums) cout << i << "   ";
    cout << endl;
    cout << n;
    cout << endl;
    return	0;
}