#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int sumofGCD(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0) sum += i;
    }
    return sum;
}

void getAll(int n){
    for(int i = 1; i < n; i++){
        int sum_gcd = sumofGCD(i);
        int sum_self = sumofGCD(sum_gcd);
        if(i == sum_self) ans.push_back(i);
    }
}

int main()
{
    getAll(3000);
    for(auto &i : ans) cout << i << "\t";
    cout << endl;
    return	0;
}