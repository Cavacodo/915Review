#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    int len = s.size();
    int ans = 0;
    for(int i = 0; i < len; i++){
        int t = s[i] - '0';
        ans += t * pow(10,len-i-1);
    }
    return ans;
}

int main()
{
    cout << solve("2648") << endl;
    return	0;
}