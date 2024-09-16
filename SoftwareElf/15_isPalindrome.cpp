#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    vector<int> v;
    while(n){
        int t = n % 10;
        v.push_back(t);
        n /= 10;
    }
    for(int i = 0; i < v.size()/2; i++){
        if(v[i] != v[v.size()-1-i]) return false;
    }
    return true;
}
int main()
{
    cout << (int)isPalindrome(998899) << endl;
    return	0;
}