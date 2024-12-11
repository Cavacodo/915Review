#include <bits/stdc++.h>
using namespace std;
string s1,s2;
bool isValid(string a,string b){
    int v[27];
    memset(v,0,sizeof v);
    for(int i = 0; i < b.size(); i++)
        v[b[i]-'a']++;
    for(int i = 0; i < a.size(); i++){
        if(v[a[i]-'a'] == 0) return false;
        v[a[i]-'a']--;
    }
    for(auto i : v){
        if(i != 0) return false;
    }
    return true;
}

int main()
{
    cin >> s1 >> s2;
    cout << (int)isValid(s1,s2) << endl;
    return	0;
}