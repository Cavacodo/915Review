#include <bits/stdc++.h>
using namespace std;

void deleteLetter(string &s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        // TODO cpp中'/0'是空字符
        if(s[i] <= '9' && s[i] >= '0') s[i] = '\0';
    }
    cout << s << endl;
}

int main()
{
    string s;
    cin >> s;
    deleteLetter(s);
    return	0;
}