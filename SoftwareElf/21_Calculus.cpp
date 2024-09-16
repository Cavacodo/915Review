#include <bits/stdc++.h>
using namespace std;

int fx(int x){
    return x*x*x + 3*x*x - x + 2;
}
int calculus(int a,int b){
    int ans = 0;
    for(int i = a; i < b; i++){
        int t = fx(i);
        ans += t;
    }
    return ans;
}

int main()
{
    
    return	0;
}