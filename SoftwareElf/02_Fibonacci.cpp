#include <bits/stdc++.h>
using namespace std;

vector<int> ans(20,0);
void dp(){
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i < 20; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
}
int dfs(int idx){
    if(idx == 0 || idx == 1) return 1;
    return dfs(idx-1) + dfs(idx-2);
}
int main()
{
    for(int i = 0; i < 20; i++) ans[i] = dfs(i);
    for(auto &i : ans) cout << i << "\t";
    cout << endl;
    return	0;
}