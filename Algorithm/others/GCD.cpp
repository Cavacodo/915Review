#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    if(a < b) swap(a,b);
    while(!b){
        int t = b;
        a = a%b;
        b = t;
    }
    return b == min(a,b) ? 1 : b;
}

int main()
{
    cout << GCD(15,22) << endl;
    return	0;
}