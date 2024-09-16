#include <bits/stdc++.h>
using namespace std;

string converter(int n){
    string l = to_string(n);
    return l.substr(l.length()-3,3);
}
int main()
{
    cout << converter(10023) << endl;
    
    return	0;
}