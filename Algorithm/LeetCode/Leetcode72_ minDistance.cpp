// DP
// 但是比较难，注意状态转移方程的书写
// 详见 https://leetcode.cn/problems/edit-distance/submissions/559531909/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(),l2 = word2.size();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i = 0; i < dp.size(); i++) dp[i][0] = i;
        for(int j = 0; j < dp[0].size(); j++) dp[0][j] = j;
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                dp[i][j] = min(dp[i-1][j] + 1,min(dp[i-1][j-1],dp[i][j-1]) + 1);
                if(word1[i-1] == word2[j-1]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            }
        }
        return dp[l1][l2];
    }
};

int main()
{
    
    
    return	0;
}