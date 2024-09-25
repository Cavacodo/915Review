#include <bits/stdc++.h>
using namespace std;

// TODO 这题没看懂子问题划分
int f(int m,int n){
    if(m == 1) return 1;
    if(n == 1) return 1;
    if(m == n) return 1 + f(m,n-1);
    else if(m < n) return f(m,m);
    else return f(m-n,n) + f(m,n-1);
}

int main()
{
    cout << f(4,3) << endl;
    return	0;
}