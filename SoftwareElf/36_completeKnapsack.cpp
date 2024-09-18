#include <bits/stdc++.h>
using namespace std;

int maxBag_2dim(vector<int> weight,int volume,vector<int> val){
    vector<vector<int>> dp(weight.size()+1,vector<int>(volume+1,0));
    for(int i = 1; i <= weight.size(); i++){
        for(int j = weight[i-1]; j <= volume; j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-weight[i-1]]+val[i-1]);
        }
    }
    return dp[weight.size()][volume];
}
int maxBag_1dim(vector<int> weight,int volume,vector<int> val){
    vector<int> dp(volume+1,0);
    for(int i = 1; i <= weight.size(); i++){
        // 完全背包第二层从头开始遍历，因为能使用多次，所以每次要参考前面被选择的情况
        for(int j = weight[i-1]; j <= volume; j++){
            dp[j] = max(dp[j],dp[j-weight[i-1]] + val[i-1]);
        }
    }
    return dp[volume];
}

int main()
{
    
    return	0;
}