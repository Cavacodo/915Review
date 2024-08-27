#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f; //定义常量

struct Edge{   //结构体定义边
    int a, b, c;
} edges[M];

int n, m, k;   //n个点,m条边,k次迭代
int dist[N], last[N]; //dist存储单源最短路径长度,last存储上一次迭代的值

void bellman_ford(){ //Bellman-Ford算法主函数

    memset(dist, 0x3f, sizeof dist); // dist初始化为无穷大

    dist[1] = 0; //源点路径长度设置为0

    // 迭代k次之后的dist代表：不超过k条边的从起点开始的最短路的距离
    for (int i = 0; i < k; i ++) { //k次迭代

        memcpy(last, dist, sizeof dist); //last记录本次迭代前的值

        for (int j = 0; j < m; j ++) {//枚举每条边

            Edge e = edges[j]; //取出一条边

            //松弛操作,更新dist值
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if (dist[n] > INF / 2) puts("impossible");
    else cout << dist[n] << endl;

    return 0;
}
