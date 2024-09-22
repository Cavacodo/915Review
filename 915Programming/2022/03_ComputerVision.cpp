#include <bits/stdc++.h>
using namespace std;

int n,c;
vector<int> v;
vector<vector<int>> ans;
vector<int> tmp;

void dfs(int res,int start){
    if(res == 0) ans.push_back(tmp);
    for(int i = start; i < v.size(); i++){
        if(res - v[i] >= 0){
            res -= v[i];
            tmp.push_back(v[i]);
            dfs(res,i+1);
            res += v[i];
            tmp.pop_back();
        }
    }
}
void solve(){
    dfs(c,0);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> c;
    int m = n; 
    while(m--){
        int t;
        cin >> t;
        v.push_back(t);
    }
    solve();
    return	0;
}