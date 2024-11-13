#include <bits/stdc++.h>
using namespace std;

void divide_array(vector<int> &v,int k){
    int n = v.size();
    int l = 0, r = n-1;
    while(l <= r){
        while(l <= r && v[r] >= k) r--;
        v[l] = v[r];
        while(l <= r && v[l] < k) l++;
        v[r] = v[l];
    }
}

int main()
{
    vector<int> v = {3,1,2,4,6,7,2,1,3,9,6};
    divide_array(v,5);
    return	0;
}