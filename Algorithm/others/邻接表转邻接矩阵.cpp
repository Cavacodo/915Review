#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int h[N],w[N],nxt[N],e[N],eidx;
int n;
int adj_m[N][N];
void add(int a,int b,int weight){
    e[eidx] = b;
    w[eidx] = weight;
    nxt[eidx] = h[a];
    h[a] = eidx;
    eidx++;
}

void converter(){
    for(int i = 0; i < 1010; i++){
        if(h[i] == -1) continue;
        for(int p = h[i]; p != -1; p = nxt[p]){
            int v = e[p];
            int weight = w[p];
            adj_m[i][v] = weight;
        }
    }
}

int main()
{
    cin >> n;
    int m = n;
    memset(h, -1, sizeof h);
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        add(a,b,w);
    }
    memset(adj_m, -1, sizeof adj_m);
    converter();
    for(int i = 0; i < 1010; i++){
        for(int j = 0; j < 1010; j++){
            if(adj_m[i][j] != -1){
                cout << i << '\t' << j << '\t' << adj_m[i][j] << endl;
            }
        }
    }
    return	0;
}