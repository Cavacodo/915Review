#include <bits/stdc++.h>
using namespace std;

// a + aa + aaa + ... + aaaa...a
int getAns(int a,int n){
    if(n == 1) return a;
    return 10 * getAns(a,n-1) + a + getAns(a,n-1);
}

int dp_prefix_sum(int a,int n){
    vector<int> dp(n+1,0);
    dp[1] = a;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] * 10 + a + dp[i-1];
    }
    return dp[n];
}
int main()
{
    cout << dp_prefix_sum(2,5) << endl;
    
    return	0;
}