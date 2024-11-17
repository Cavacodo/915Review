#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void allCombo(int k){
    sort(v.begin(),v.end());
    int l = 0, r = v.size() - 1;
    while(l <= r){
        if(v[l] == v[l-1]){
            l++;
            continue;
        }
        if(v[r] == v[r+1]){
            r--;
            continue;
        }
        if(v[l] + v[r] == k){
            cout << v[l] << '\t' << v[r] << endl;
            l++;
            r--;
        }else if(v[l] + v[r] > 0){
            r--;
        }else l++;
    }
}

int main()
{
    v = {1,2,3,4,6,7,8,5,9,23,4,3,6,8};
    int k = 10;
    allCombo(k);
    return	0;
}