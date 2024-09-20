#include <bits/stdc++.h>
#define N 100
using namespace std;

int m;
int matrix[N][N];

int calMainDiagonal(){
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == j) cnt += matrix[i][j];
        }
    }
    return cnt;
}

int calViceDiagonal(){
    int cnt = 0;
    for(int i = m-1; i >= 0; i--){
        for(int j = m-1; j >=0; j--){
            if(i == j) cnt += matrix[i][j];
        }
    }
    return cnt;
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    cout << calMainDiagonal() << endl;
    cout << calViceDiagonal() << endl;
    return	0;
}