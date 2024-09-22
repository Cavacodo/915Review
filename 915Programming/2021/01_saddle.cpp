#include <bits/stdc++.h>
using namespace std;
#define N 1010
int n,m;
int matrix[N][N];

void solve(){
    vector<int> v(n,0);
    // m*n
    for(int i = 0; i < n; i++){
        int mx = 0;
        for(int j = 0; j < m; j++){
            if(matrix[mx][i] < matrix[j][i]){
                mx = j;
            }
        }
        v[i] = mx;
    }
    for(int i = 0; i < m; i++){
        int mn = 0;
        for(int j = 0; j < n; j++){
            if(matrix[i][mn] > matrix[i][j]){
                mn = j;
            }
        }
        //最小此时是i行mn列
        if(v[mn] == i){
            cout << i+1 << '\t' << mn+1 << '\t' << matrix[i][mn] << endl;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    solve();
    return	0;
}