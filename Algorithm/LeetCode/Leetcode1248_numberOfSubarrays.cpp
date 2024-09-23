#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> prefix(nums.size()+1,0);
        for(int i = 0; i < nums.size(); i++){
            int ti = 0;
            if(nums[i] % 2) ti = 1;
            prefix[i+1] = ti + prefix[i];
        }
        unordered_map<int,int> umap;
        umap[0] = 1;
        for(int i = 1; i <= nums.size(); i++){
            if(umap.count(prefix[i]-k)) ans += umap[prefix[i]-k];
            umap[prefix[i]]++;
        }
        return ans;
    }
};

int main()
{
    
    return	0;
}