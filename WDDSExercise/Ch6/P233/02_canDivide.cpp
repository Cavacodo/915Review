#include <bits/stdc++.h>
using namespace std;
//原题使用邻接表存储，现在使用邻接矩阵存储
#define MAXV 5
typedef struct{
    int numVertices,numEdge;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

typedef struct pairs{
    int node;
    int color;
    pairs(int x) : node(x),color(-1){};
    pairs(int x,int c) : node(x),color(c){};
};
bool canDivide(MGraph g){
    vector<pairs*> v;
    for(int i = 0; i < MAXV; i++) v.push_back(new pairs(i));
    for(int i = 0; i < MAXV; i++){
        pairs* cur = v[i];
        if(cur->color == -1) cur->color = 0; 
        for(int j = 0; j < MAXV; j++){
            if(g.Edge[i][j] && v[j]->color == cur->color) return 0;
            if(g.Edge[i][j] && v[j]->color == -1) v[j]->color = cur->color == 1 ? 0 : 1;
        }
    }
    return 1;
}

int main()
{
    
    
    return	0;
}