#include <bits/stdc++.h>
using namespace std;
#define N 100

int m,n;
int board[N][N];

void printRoute(vector<vector<int>> &v){
    deque<int> route;
    route.push_back(board[m-1][n-1]);
    int i = m-1, j = n-1;
    while(true){
        int pre = v[i][j] - board[i][j];
        if(i > 0 && pre == v[i-1][j]){
            route.push_back(board[i-1][j]);
            i--;
        }else if(j > 0 && pre == v[i][j-1]){
            route.push_back(board[i][j-1]);
            j--;
        }
        if(i == 0 && j == 0) break;
    }
    while(!route.empty()){
        int t = route.front();
        if(route.size() > 1) cout << t << "->";
        else cout << t << endl;
        route.pop_front();
    }
}
void minSum(){
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = board[0][0];
    for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + board[i][0];
    for(int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + board[0][j];
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = board[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[m-1][n-1] << endl;
    printRoute(dp);
}
int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    minSum();
    return	0;
}