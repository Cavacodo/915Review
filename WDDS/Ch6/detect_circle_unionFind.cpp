/**
* 并查集判断无向图是否具有环的算法思想：
* 并查集将同一子集中的各个元素，组织成一棵树。将存在边的顶点进行合并，若顶点w和顶点v存在边，则将它们合并，因此合并后的同一子集代表它们彼此是联通的，若u,v合并失败
* 则代表它们此时已经属于同一个子集了，已经联通了，由于u和v还有边，那么连通图再加1条边，则会出现环，
* 因此当遍历一条边时，边的两个顶点若属于同一集合，则代表该图存在环，合并失败的次数即为环的个数
**/

#include <bits/stdc++.h>
using namespace std;
#define N 10
int parent[N];
// 并查集判断环路的思路在于将存在边的顶点进行合并，若顶点w和顶点v存在边，则将它们合并，因此合并后的同一子集代表它们彼此是联通的
// 但树如果存在环路，那么u,v合并失败则代表它们此时已经属于同一个子集了，已经联通了，由于u和v还有边，那么连通图再加1条边，则会出现环
void Init(int n){
    for(int i = 0; i < n; i++) parent[i] = i;
}
int find(int x){
    return parent[x] == x ?  x : find(parent[x]);
}
int Union(int x,int y){
    int root1 = find(x);
    int root2 = find(y);
    if(root1 == root2) return 1;    // 存在环
    if(parent[root1] > parent[root2]){
        parent[root2] += parent[root1]; // 大树生成了
        parent[root1] = root2;  // 小树合并到大树上
    }else{
        parent[root1] += parent[root2];
        parent[root2] = parent[root1];
    }
    return 0;
}


int main()
{
    Init(4);
    int edges[4][2] = {{0,1},{1,2},{1,3},{2,3}};
    for(int i = 0; i < 4; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        if(Union(x,y)) cout << "Yes" << endl;
    }

    return	0;
}