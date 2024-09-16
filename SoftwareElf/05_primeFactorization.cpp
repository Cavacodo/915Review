#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
void prime_factorization(int n){
    while(n > 1){
        for(int i = 2; i <= n; i++){
            if(isPrime(i) && (n % i == 0)){
                cout << i;
                n /= i;
                if(n > 1) cout << "*";
                break;
            }
        }
    }
}

int main()
{
    prime_factorization(190);
    cout << endl;
    return	0;
}