#include <bits/stdc++.h>
using namespace std;
#define N 100
int n;
int board[N][N];
int maxLength(){
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0] = board[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = board[i][j] + dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + board[i][j];
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) ans = max(ans,dp[n-1][i]);
    return ans;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <=i; j++){
            cin >> board[i][j];
        }
    }
    cout << maxLength() << endl;
    return	0;
}