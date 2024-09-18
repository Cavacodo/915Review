// 0-1背包问题
#include <bits/stdc++.h>
using namespace std;

int knapsack_2dim(vector<int> weight,int volume,vector<int> val){
    // 先要初始化 或者说 全遍历
    vector<vector<int>> dp(weight.size()+1,vector<int>(volume+1,0));
    for(int i = 1; i <= weight.size(); i++){
        // 第二层for前到后，后到前无所谓，因为只使用上层数据，和本层前后无关系
        for(int j = 0; j <= volume; j++){
            if(j < weight[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]] + val[i-1]);
        }
    }
    return dp[weight.size()][volume];
}

int knapsack_1dim(vector<int> weight,int volume,vector<int> val){
    vector<int> dp(volume+1,0);
    for(int i = 1; i <= weight.size(); i++){
        // 每个物品只能选用一次，因此第二层使用倒叙遍历保证每次遍历都适用的是没选的+选上后
        for(int j = volume; j >= weight[i-1]; j--){
            dp[j] = max(dp[j],dp[j-weight[i-1]] + val[i-1]);
        }
    }
    return dp[volume];
}

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
    vector<int> weight = {2,3,4,5};
    vector<int> val = {3,4,5,6};
    cout << maxBag_2dim(weight,8,val) << endl;
    return	0;
}