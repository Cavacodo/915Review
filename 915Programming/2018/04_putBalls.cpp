//终于有一道有点意思的题
//回溯法秒了
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> sv;
int m,n;
void dfs(int n,int idx,int res){
    if(sv.size() == m && res == 0){
        v.push_back(sv);
        return;
    }
    for(int i = idx; i <= n; i++){
        if(sv.size() < m){
            cout << endl;
            res -= i;
            sv.push_back(i);
            dfs(n,i,res);
            res += i;
            sv.pop_back();
        }
    }
}
void solve(){
    cin >> m >> n;
    dfs(n,0,n);
    return;
}

int main()
{
    solve();
    return	0;
}