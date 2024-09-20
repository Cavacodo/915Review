#include <bits/stdc++.h>
using namespace std;

void statistic(string &s){
    vector<int> v(10,0);
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= '9' && s[i] >= '0'){
            int t = s[i] - '0';
            v[t]++;
        }
    }
    for(int i = 0; i < 10; i++) cout << i << ':' << v[i] << "\t";
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    statistic(s);
    return	0;
}