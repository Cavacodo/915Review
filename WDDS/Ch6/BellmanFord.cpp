#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 边的结构体，包含起点、终点和权重
struct Edge {
    int from, to, weight;
};

// 图的结构体，包含顶点数、边列表
struct Graph {
    int vertices;
    vector<Edge> edges;
    
    // 添加边
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }
};

// Bellman-Ford 算法
bool bellmanFord(Graph& graph, int source, vector<int>& distances, vector<int>& predecessors) {
    int V = graph.vertices;
    int E = graph.edges.size();
    
    // 初始化距离表和前驱节点表
    distances.assign(V, numeric_limits<int>::max());
    predecessors.assign(V, -1); // 没有强制要求predecessors,用来寻路的
    distances[source] = 0;

    // 松弛操作，对所有边重复 V-1 次
    // 不能改变for的内外顺序，每一次都是对所有边遍历一遍共V-1遍，不是一个顶点遍历V-1遍
    for (int i = 1; i < V; ++i) {
        for (const auto& edge : graph.edges) {
            int u = edge.from;
            int v = edge.to;
            int weight = edge.weight;
            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }
        }
    }

    // 检查负权回路
    for (const auto& edge : graph.edges) {
        int u = edge.from;
        int v = edge.to;
        int weight = edge.weight;
        if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return false; // 如果还能松弛，则说明图中存在负权回路
        }
    }

    return true;
}

int main() {
    Graph g;
    g.vertices = 5; // 设置顶点数
    // 添加边
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    vector<int> distances;
    vector<int> predecessors;

    if (bellmanFord(g, 0, distances, predecessors)) {
        cout << "Vertex   Distance from Source" << endl;
        for (int i = 0; i < g.vertices; ++i) {
            cout << i << "\t" << distances[i] << endl;
        }
    }

    return 0;
}
