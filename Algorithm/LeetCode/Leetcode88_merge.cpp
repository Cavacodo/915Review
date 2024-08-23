#include <bits/stdc++.h>
using namespace std;
// 追求O(m+n)
// mergesort
// 为了防止出现移动元素时附加的O(n)时间复杂度，我们可以采用从后向前的方法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0){
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while(i >= 0) nums1[k--] = nums1[i--];
        while(j >= 0) nums1[k--] = nums2[j--];
        // 这两行仅执行一个
    }
};
int main()
{
    
    
    return	0;
}