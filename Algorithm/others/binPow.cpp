//快速幂
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll a,ll b){
    if(!b) return 1;
    ll res = binpow(a,b/2);
    if(b % 2)
        return res * res * a;
    else return res * res;
}

//非递归
ll binpow(ll a,ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    
    return	0;
}