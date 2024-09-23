// 非常巧妙的将0转化成-1求0
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        vector<int> prefix(nums.size()+1,0);
        for(int i = 1; i <= nums.size(); i++){
            prefix[i] = prefix[i-1] + (nums[i-1] == 0 ? -1 : 1);
        }
        unordered_map<int,int> umap;
        umap[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            if(umap.count(prefix[i])) ans = max(ans,i - umap[prefix[i]]);
            else umap[prefix[i]] = i;
        }
        return ans;
    }
};

int main()
{
    
    return	0;
}