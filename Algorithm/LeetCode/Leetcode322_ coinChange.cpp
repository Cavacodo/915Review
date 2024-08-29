#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        for(int i = 1; i <= amount; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j] && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    
    
    return	0;
}