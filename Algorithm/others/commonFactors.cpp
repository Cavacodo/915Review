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
    int a;
    cin >> a;
    vector<int> cf;
    // 无重复元素的情况
    for(int i = 2; i <= a; i++){
        if(isPrime(i) && !(a % i)){
            cf.push_back(i);
            a /= i;
        }
    }
    for(auto i:cf) cout << i << "\t";
    cout << endl;
    return	0;
}