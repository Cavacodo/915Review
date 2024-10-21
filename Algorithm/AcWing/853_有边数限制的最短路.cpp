// 本题的难点不在负权回路，因为有也不影响
// 限定了K步，因此最多松弛K次。
// 理解Backup的作用
#include <bits/stdc++.h>
using namespace std;
#define N 510

int n,m,k;
int distances[N];
int backup[N];
struct Edge{
    int from,to,weight;
};
typedef struct Graph{
    int verticals;
    vector<Edge> edges; 
    void push_edges(int from,int to,int weight){
        edges.push_back({from,to,weight});
    }
}G;
G g;

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < N; i++) distances[i] = INT_MAX;
    distances[1] = 0;
    g.verticals = n;
    int t = m;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        g.push_edges(a,b,c);
    }
    for(int i = 0; i < k; i++){
        memcpy(backup, distances, sizeof distances);
        for(const auto& edge : g.edges){
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;
            // Backup保存上一步状态，防止出现遍历边时修改多步的情况出现
            if(backup[from] != INT_MAX){
                distances[to] = min(distances[to],backup[from]+weight);
            }
        }
    }
    if(distances[n] == INT_MAX){
        cout << "impossible" << endl;
        return 0;
    }
    cout << distances[n];
    return	0;
}