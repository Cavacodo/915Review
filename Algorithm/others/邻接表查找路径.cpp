#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int h[N];
int idx = 0;
struct Edge{
    int to, nxt;
};
Edge edges[N];
void add(int from,int to){
    edges[idx].to = to;
    edges[idx].nxt = h[from];
    h[from] = idx;
    idx++;
}
int get_next(int u,int ux){
    int indicator = -1;
    for(int p = h[u]; p != -1; p = edges[p].nxt){
        if(edges[p].to == ux) indicator = 1;
        if(indicator == 1) return edges[p].to;
    }
    return -1;
}
int main()
{
    int n;
    memset(h,-1,sizeof h);
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    cout << get_next(1,2) << endl;
    return	0;
}
