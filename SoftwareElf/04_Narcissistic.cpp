// 水仙花数
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100;
    while(n < 1000){
        int l1 = n / 100, l2 = (n%100) / 10, l3 = n%10;
        if(n == l1*l1*l1 + l2*l2*l2 + l3*l3*l3){
            cout << n << "\t";
        }
        n++;
    }
    cout << endl;
    return	0;
}