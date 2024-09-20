#include <bits/stdc++.h>
using namespace std;

int n;
int price;
vector<int> price_per_piece;
int ans = 0;
void dfs(int idx,int res){
    if(res == 0){
        ans++;
        return;
    }
    for(int i = idx; i < n; i++){
        if(res - price_per_piece[i] >= 0){
            res -= price_per_piece[i];
            dfs(i+1,res);
            res += price_per_piece[i];
        }
    }
}

int main()
{
    cin >> n >> price;
    int m = n;
    while(m--){
        int p;
        cin >> p;
        price_per_piece.push_back(p);
    }
    dfs(0,price);
    cout << ans << endl;
    return	0;
}