#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pa;
    int find(int x){
        return pa[x] == x ? x : find(pa[x]);
    }
    bool Union(int x,int y){
        if(find(x) == find(y)) return false;
        pa[find(x)] = find(y);
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        for(int i = 0; i < 1010; i++) pa.push_back(i);
        for(auto& a : edges){
            bool st = Union(a[0],a[1]);
            if(!st) ans = a;
        }
        return ans;
    }
};

int main()
{
    
    return	0;
}
