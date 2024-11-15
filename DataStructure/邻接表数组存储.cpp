#include <bits/stdc++.h>
using namespace std;
// h数组的下标为结点的编号，e,w,nxt数组的下标为边的编号，idx为边的编号

// 假设现在有的边如下：
// 起点    终点     边权
//  1       2       9
//  2       4       1
//  1       3       3
//  3       4       5

// h[N]数组是头节点数组
// w[N]数组存储对应边上权值。
// nxt[N]数组存储下一条边的编号
// e[N]数组存储对应边的终点
// eidx存储当前指针
const int N = 10;
int h[N],w[N],nxt[N],e[N],eidx;

// 添加一条从a指向b,权值为weigt的边
void add(int a,int b,int weight){
    e[eidx] = b;    //  当前指向边的终点是b
    w[eidx] = weight;   //  权值是weight
    nxt[eidx] = h[a];   //  连接到h[a]的边表上
    h[a] = eidx;     //  更新h[a]指针位置，就是放在永远在第一个，从而实现往后查找
    eidx++;
} 
//  遍历u开始的所有邻接边
void Iterator(int u){
    int p = h[u];   // 边的编号
    while(p != -1){
        int v = e[p];
        int we = w[v];
        p = nxt[p];
        cout << u << "--->" << v << '\t' <<  "weight:" << we << endl;
    }
}

int main()
{
    // m是边的个数，n是顶点个数
    int m,n;
    cin >> m >> n;
    memset(h, -1 ,sizeof h);
    eidx = 1;
    while(m--){
        int a,b,we;
        cin >> a >> b >> we;
        add(a,b,we);
    }
    for(int i = 1; i <= n; i++){
        Iterator(i);
    }
    return	0;
}