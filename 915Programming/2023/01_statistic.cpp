#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(51,0);

int main()
{
    cin >> n;
    int m = n; 
    while(m--){
        int t;
        cin >> t;
        v[t]++;
    }
    for(int i = 0; i < 51; i++){
        if(v[i] != 0){
            cout << i << '\t' << v[i] << endl;
        }
    }
    return	0;
}