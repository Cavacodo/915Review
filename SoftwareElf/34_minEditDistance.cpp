#include <bits/stdc++.h>
using namespace std;

int minDistance(string s1,string s2){
    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
    for(int i = 0; i <= l1; i++) dp[i][0] = 1;
    for(int i = 0; i <= l2; i++) dp[0][i] = 1;
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1],dp[i-1][j-1])+1);
            // 抹除掉尽管相同但树仍旧+1的操作
            if(s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
        }
    }
    return dp[l1][l2];
}

int main()
{
    cout << minDistance("horse","ros") << endl;
    return	0;
}