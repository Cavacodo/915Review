#include <bits/stdc++.h>
using namespace std;
int getNumberOfRobot(int n){
    if(n <= 4) return n;
    vector<int> v(n,0);
    vector<int> prefix_sum(n,0);
    for(int i = 0; i < 5; i++){
        v[i] = i;
        prefix_sum[i] = i + prefix_sum[i-1];
    }
    for(int i = 5; i <= n; i++){
        v[i] = i + prefix_sum[i-4];
        prefix_sum[i] = i + prefix_sum[i-1];
    }
    return v[n];
}
int main()
{
    int n;
    cin >> n;
    cout << getNumberOfRobot(n) << endl;
    return	0;
}