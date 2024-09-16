#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    for(int i = 101; i < 200; i++)
        if(isPrime(i)) cout << i << "\t";
    cout << endl;
    
    return	0;
}