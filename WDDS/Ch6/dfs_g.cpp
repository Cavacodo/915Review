#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10010
int n;
int g[N][N];
int u[N];
int cnt = 0;
void dfs(int n,int k){
    if(cnt == n) return;
    for(int i = 1; i <= n; i++){
        if(g[k][i] == 1 && u[i] == 0){
            cout << i << ' ';
            u[i] = 1;
            cnt++;
            dfs(n,i);
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            g[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++) u[i] = 0;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    for(int i = 1; i <= n; i++){
        dfs(n,i);
    }
    return 0;
}