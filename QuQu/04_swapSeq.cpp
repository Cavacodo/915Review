#include <bits/stdc++.h>
using namespace std;

void solve(string &s){
    deque<int> dq;
    dq.push_back(0);
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == ' ') dq.push_back(i);
    }
    vector<string> v;
    for(int i = 1; i < dq.size(); i++){
        v.push_back(s.substr(dq[i-1],dq[i]));
    }
    for(int i = v.size()-1; i >= 0; i--){
        
    }
}

int main()
{
    
    return	0;
}