#include <bits/stdc++.h>
using namespace std;

int n;
int solve(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    if(n <= 2) return dp[n];
    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int main()
{
    cin >> n;
    cout << solve(n) << endl;
    return	0;
}