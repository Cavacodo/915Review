#include <bits/stdc++.h>
using namespace std;

string s;
bool isLegal(){
    int sNum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'I') ++sNum;
        else if(s[i] == 'O'){
            if(sNum > 0) --sNum;
            else return false;
        }
    }
    return true;
}

int main()
{
    cin >> s;
    cout << isLegal() << endl;
    return	0;
}