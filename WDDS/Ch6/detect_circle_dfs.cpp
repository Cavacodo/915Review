#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, q[N], top;
int st[N];  // 0表示没有遍历过，1表示在递归当中，2表示已经遍历完了

struct Node
{
    int id;
    Node* next;
    Node(int _id) : id(_id), next(NULL){}
} *head[N];

void add(int a, int b)
{
    Node* p = new Node(b);
    p->next = head[a];      // 头插法
    head[a] = p;
}

bool dfs(int u)     // 如果有环的话返回false
{
    st[u] = 1;      // 标记当前点在递归中

    for (Node* p = head[u]; p; p = p->next)
    {
        int j = p->id;
        if (!st[j])     // 如果没有搜过的话（0）就直接搜
        {
            if (!dfs(j)) return false;  // 如果搜的过程中出现了环，直接false
        }
        else if (st[j] == 1) return false;   // 否则如果发现这个点在递归当中，直接false
    }

    q[top ++] = u;

    st[u] = 2;      // 标记当前点已经遍历完了

    return true;
}

// 基于深搜的话要遍历所有点，因为这个图不一定是联通的
bool topsort()
{
    for (int i = 1; i <= n; i ++)
        if (!st[i] && !dfs(i)) // 如果没遍历的话就遍历它，如果发现有环的话直接false
            return false;
    return true;
}

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    if (topsort())
    {
        // 因为得到的是拓扑排序的逆序序列，所以要倒序输出
        for (int i = n - 1; i >= 0; i -- ) cout << q[i] << ' ';
        cout << endl;
    }
    else puts("-1");

    return 0;

}