#include <bits/stdc++.h>
using namespace std;

double getSum(int n){
    double ans = 0.0;
    for(double i = 0.0; i < n; i++){
        ans += (2 + i) / (1 + i);
    }
    return ans;
}

int main()
{
    cout << getSum(20) << endl;
    return	0;
}