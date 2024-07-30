#include <bits/stdc++.h>
using namespace std;

int N,M;

struct City
{
    int size = 0;
    vector<int> adj;
};


int main(){
    cin >> N >> M;
    int tmp = M;
    City city[N];
    while (tmp--)
    {
        int a,b;
        cin >> a >> b;
        city[a].size++;
        city[a].adj.push_back(b);
        city[b].size++;
        city[b].adj.push_back(a);
    }
    
    return 0;
}