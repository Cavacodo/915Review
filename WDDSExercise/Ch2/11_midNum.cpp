#include <bits/stdc++.h>
using namespace std;

int getMidNum(vector<int> v1,vector<int> v2){
    int m = v1.size(), n = v2.size();
    int mid = (m + n + 1) >> 1;
    vector<int> ans(mid,0);
    int l = 0 ,r = 0, cnt = 0;
    while(cnt < mid){
        while(cnt < mid && v1[l] <= v2[r]) ans[cnt++] = v1[l++];
        while(cnt < mid && v1[l] > v2[r]) ans[cnt++] = v2[r++];
    }
    return ans[mid-1];
}

int main()
{
    vector<int> v1 = {11,13,15,17,19};
    vector<int> v2 = {2,4,6,8,12,20};
    cout << getMidNum(v1,v2) << endl;
    return	0;
}