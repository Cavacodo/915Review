#include <bits/stdc++.h>
using namespace std;

int m,n;
unordered_map<string,int> umap;
void Election(){
    int t = n;
    int cnt = 0;
    while(t--){
        string s;
        cin >> s;
        umap[s] = 0;
    }
    while(m--){
        string s;
        cin >> s;
        umap[s]++;
    }
    for(auto &pair : umap) cout << pair.first << ':' << pair.second << endl;
}
int main()
{
    cin >> m >> n;
    Election();
    return	0;
}