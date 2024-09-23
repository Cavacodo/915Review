// 本题最佳时间复杂度为O(N^3)
// TODO 不错的题 reinforce 前缀和and差分 + dp
#include <bits/stdc++.h>
using namespace std;
#define N 1010
int m,n;
int matrix[N][N];
struct Pair{
    int x,y;
};

// b是更右下角的
int calSubMatrix(vector<vector<int>> v,Pair a,Pair b){
    return v[b.x][b.y] - v[b.x][b.y-1] - v[a.x][a.y] + v[a.x][a.y-1];
}

void solve(vector<vector<int>> prefix){
    Pair mx,mn;
    int ans = INT_MIN;
    int gans = INT_MIN;
    Pair x,y;
    for(int i = 0; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            vector<int> v(n,0);
            vector<int> dp(n,0);
            int ans = INT_MIN;
            for(int k = 1; k <= n; k++){
                Pair t1 = {j,k};
                Pair t2 = {i,k};
                v[k-1] = calSubMatrix(prefix,t2,t1);
            }
            dp[0] = v[0];
            int right = 0;
            for(int k = 1; k < n; k++){
                dp[k] = max(dp[k-1] + v[k],dp[k]);
            }
            for(int k = 0; k < n; k++){
                if(dp[k] >= dp[right]) right = k;
                ans = max(ans,dp[k]);
            }
            int mn = INT_MAX;
            int left = 0;
            for(int k = 0; k < right; k++){
                if(dp[k] == v[k] && mn > abs(k-right)){
                    mn = right-k;
                    left = k;
                }
            }
            if(ans > gans){
                gans = ans;
                x.x = i;
                x.y = left+1;
                y.x = j;
                y.y = right+1;
            }
        }
    }
    cout << "max val == " << gans << endl;
    cout << x.x << '\t' << x.y << endl;
    cout << y.x << '\t' << y.y << endl; 

}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    vector<vector<int>> prefix_sum(m+1,vector<int>(n+1,0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] + matrix[i-1][j-1] - prefix_sum[i-1][j-1];
        }
    }
    solve(prefix_sum);
    return	0;
}