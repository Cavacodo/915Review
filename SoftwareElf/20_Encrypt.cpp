#include <bits/stdc++.h>
using namespace std;

void encrypt(string &s,int offset){
    int n = s.size();
    for(int i = 0; i < n; i++){
        s[i] += i + offset; 
    }
}

void decrypt(string &s,int offset){
    int n = s.size();
    for(int i = 0; i < n; i++){
        s[i] -= i + offset;
    }
}

int main()
{
    string s = "mrsoft";
    encrypt(s,5);
    cout << s << endl;
    decrypt(s,5);
    cout << s << endl;
    return	0;
}