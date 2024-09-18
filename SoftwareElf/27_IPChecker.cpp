#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s){
    vector<string> v;
    int start = 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '.') continue;
        else{
            cnt++;
            string tmp = s.substr(start,i-start);
            v.push_back(tmp);
            start = i + 1;
        }
        if(cnt==3){
            string tmp = s.substr(start,s.size()-1-i);
            v.push_back(tmp);
        }
    }
    return v;
}

bool isValid(string &s){
    vector<string> v = split(s);
    for(auto &i : v){
        int len = i.size();
        if(len > 3) return false;
        int t = stoi(i);
        if(to_string(t) != i) return false;
        if(t > 255) return false; 
    }
    return true;
}

int main()
{
    string s = "005.231.23.1";
    vector<string> t = split(s);
    for(auto i : t) cout << i << endl;
    cout << (int)isValid(s) << endl;
    return	0;
}