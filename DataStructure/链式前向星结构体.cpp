#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int h[N];

typedef struct Edge{
    int to,nxt,weight;
};
int eidx = 0;
Edge edges[N];
void add(int from,int to,int weight){
    edges[eidx].to = to;
    edges[eidx].weight = weight;
    edges[eidx].nxt = h[from];
    h[from] = eidx;
    eidx++;
}

int main()
{
    memset(h,-1,sizeof h);

    return	0;
}