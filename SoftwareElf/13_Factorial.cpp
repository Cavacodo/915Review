#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll getFactorial(int n){
    if(n <= 1) return (ll)1;
    return (ll)n * getFactorial(n-1);
}

ll getSum(int n){
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += getFactorial(i);
    return ans;
}

int main()
{
    cout << getSum(20) << endl;
    return	0;
}