#include <bits/stdc++.h>
using namespace std;

void solve(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            string s1 = s.substr(0,i);
            string s2= s.substr(i+1,s.size());
            s = s1 + "%20" + s2;
        }
    }
}

int main()
{
    string s = " 20nks 213 842k ";
    solve(s);
    cout << s << endl;
    return	0;
}