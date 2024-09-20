#include <bits/stdc++.h>
using namespace std;

void statistic(string s){
    int nums = 0,letters = 0,others = 0;
    for(int i = 0; i < s.size(); i++){
        char t = s[i];
        if((t <= 'z' && t >= 'a')||(t <= 'Z' && t >= 'A')) letters++;
        else if(t >= '0' && t <= '9') nums++;
        else others++;
    }
    cout << "Numbers:" << nums << endl;
    cout << "Letters:" << letters << endl;
    cout << "Others:" << others << endl; 
}

int main()
{
    string s;
    cin >> s;
    statistic(s);
    return	0;
}