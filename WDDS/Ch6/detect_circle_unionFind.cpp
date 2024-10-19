/**
 * 并查集判断无向图是否具有环的算法思想：
 * 并查集将同一子集中的各个元素，组织成一棵树。将存在边的顶点进行合并，若顶点w和顶点v存在边，则将它们合并，因此合并后的同一子集代表它们彼此是联通的，若u,v合并失败
 * 则代表它们此时已经属于同一个子集了，已经联通了，由于u和v还有边，那么连通图再加1条边，则会出现环，
 * 因此当遍历一条边时，边的两个顶点若属于同一集合，则代表该图存在环，合并失败的次数即为环的个数
 **/

#include <bits/stdc++.h>
using namespace std;

vector<int> pa;
int find(int k)
{
    return pa[k] == k ? k : find(pa[k]);
}
void Union(int a, int b)
{
    pa[find(b)] = find(a);
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    for (int i = 0; i < numCourses; i++)
        pa.push_back(i);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        vector<int> tmp = prerequisites[i];
        if (find(tmp[1]) == find(tmp[0]))
            return false;
        Union(tmp[0], tmp[1]);
    }
    return true;
}
int main()
{
    vector<vector<int>> p = {{1,4},{2,4},{3,1},{3,2}};
    canFinish(5,p);
    return 0;
}