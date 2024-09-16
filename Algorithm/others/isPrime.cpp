// 素数筛
// 仅看sqrt(n)内的元素就行了
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
        if(!(n % i)) return false;
    return true;
}
int main()
{
    
    
    return	0;
}