#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v){
    deque<int> odd;
    deque<int> even;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2) odd.push_back(v[i]);
        else even.push_back(v[i]);
    }
    for(int i = 0 ; i < odd.size(); i++){
        v[i] = odd[i];
    }
    for(int i = odd.size(); i < v.size(); i++){
        v[i] = even[i-odd.size()];
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7};
    solve(v);
    for(auto &i : v) cout << i << '\t' << endl;
    return	0;
}