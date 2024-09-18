// 0-1背包问题
#include <bits/stdc++.h>
using namespace std;

// 2dim
int maxVal(int n,int vol,vector<int> &w,vector<int> &v){
    vector<vector<int>> dp(n+1,vector<int>(vol+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= vol; j++){
            // 只有选了没选两种情况
            if(j < w[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
        }
    }
    return dp[n][vol];
}

int maxVal_1dim(int n,int vol,vector<int> &w,vector<int> &v){
    vector<int> dp(vol+1,0);
    for(int i = 0; i< n; i++){
        for(int j = vol; j >= w[i]; j--){
            dp[j] = max(dp[j-w[i]]+v[i],dp[j]);
        }
    }
    return dp[vol];
}

int main()
{
    int vol = 8, n = 4;
    vector<int> w = {2,3,4,5};
    vector<int> v = {3,4,5,6};
    cout << maxVal_1dim(n,vol,w,v) << endl;
    return	0;
}