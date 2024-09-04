#include <bits/stdc++.h>
using namespace std;
#define MAXV 5
typedef struct{
    int numVertices,numEdge;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

// 有向图，同时出度大于入度数的称为K顶点
int calKVertices(MGraph g){
    vector<int> inDeg(MAXV,0);
    vector<int> outDeg(MAXV,0);
    int ans = 0;
    for(int i = 0; i < MAXV; i++){
        int cnt = 0;
        int cnt2 = 0;
        for(int j = 0; j < MAXV; j++){
            if(g.Edge[i][j]) cnt++;
            if(g.Edge[j][i]) cnt2++;
        }
        outDeg[i] = cnt;
        inDeg[i] = cnt2;
        if(cnt > cnt2) ans++;
    }
    return ans;
}
int main()
{
    
    
    return	0;
}