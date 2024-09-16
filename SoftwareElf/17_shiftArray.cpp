#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v,int l,int end){
    for(int i = l; i < l + (end-l)/2; i++) swap(v[i],v[end-1-(i-l)]);
}
void shiftArray(vector<int> &v,int n){
    reverse(v,0,v.size());
    reverse(v,0,n);
    reverse(v,n,v.size());
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8};
    shiftArray(v,3);
    for(auto &i : v) cout << i << "\t";
    cout << endl;
    return	0;
}