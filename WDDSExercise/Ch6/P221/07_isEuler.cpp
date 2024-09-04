#include <bits/stdc++.h>
using namespace std;
#define MAXV 5

typedef struct{
    int numVertices,numEdge;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

bool isEuler(MGraph g){
    vector<int> deg(MAXV,0);
    for(int i = 0; i < MAXV; i++){
        for(int j = 0; j < MAXV; j++){
            if(g.Edge[i][j] && g.Edge[i][j] != INT_MAX) deg[i]++;
        }
    }
    int cnt = 0;
    for(auto &i : deg) if(i % 2) cnt++;
    if(cnt == 2 || !cnt) return true;
    return false;  
}
int main()
{
    
    
    return	0;
}