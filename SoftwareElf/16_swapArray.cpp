#include <bits/stdc++.h>
using namespace std;

void swapArray(vector<int> &v){
    int mx = 0, mn = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] >= v[mx]) mx = i;
        if(v[i] <= v[mn]) mn = i;
    }
    swap(v[mx],v[0]);
    swap(v[mn],v[v.size()-1]);
}

int main()
{
    vector<int> arr = {1,-1,4,5,1,9,8};
    swapArray(arr);
    for(auto &i : arr) cout << i << "\t";
    cout << endl;
    return	0;
}