#include <bits/stdc++.h>
using namespace std;

int getGCD(int m,int n){
    while(n != 0){
        int tmp = n;
        n = m % n;
        m = tmp;
    }
    return m;
}

int getLCM(int m,int n){
    return (m / getGCD(m,n)) * n;
}

int main()
{
    cout << getGCD(90,32) << endl;
    cout << getLCM(90,32) << endl; 
    
    return	0;
}