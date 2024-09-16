#include <bits/stdc++.h>
using namespace std;
void printNum(int n){
    string s = to_string(n);
    cout << s.size() << endl;
    for(int i = s.size()-1; i >= 0; i--) cout << s[i];
    cout << endl;
}

void printNum_usual(int n){
    vector<int> v;
    while(n){
        int t = n % 10;
        v.push_back(t);
        n /= 10;
    }
    cout << v.size() << endl;
    for(auto &i : v) cout << i;
    cout << endl;
}
int main()
{
    printNum_usual(8764223);
    return	0;
}