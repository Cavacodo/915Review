#include <bits/stdc++.h>
using namespace std;
int exclude3(int n){
    vector<int> v(n+1,1);
    int idx = 1;
    int num = 1;
    while(true){
        if(idx >= n) idx = (idx + 1) % n;
        else idx++;
        if(v[idx] && num < 3) num++; 
        if(v[idx] && num == 3){
            v[idx] = 0;
            num = 1;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(v[i]) cnt++;
        if(cnt == 1) break; 
    }
    for(int i = 1; i <= n; i++) if(v[i]) return i;
}

int main()
{
    cout << exclude3(5) << endl;
    return	0;
}