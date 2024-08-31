// 合并有序数组
// 力扣刷到过
#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1,vector<int> v2){
    int m = v1.size(), n = v2.size();
    vector<int> ans;
    int l = 0, r = 0;
    while(l < m && r < n){
        while(l < m && v1[l] <= v2[r]) ans.push_back(v1[l++]);
        while(r < n && v1[l] > v2[r]) ans.push_back(v2[r++]);
    }
    if(l < m){
        for(l;l<m;l++) ans.push_back(v1[l]);
    }else if(r < n){
        for(r;r<n;r++) ans.push_back(v2[r]);
    }
    return ans;
}

int main()
{
    vector<int> v1 = {1,2,3,4,5,6};
    vector<int> v2 = {-3,-2,-1,0,9};
    vector<int> ans = merge(v1,v2);
    for(auto &i : ans) cout << i << "\t";
    cout << endl;
    return	0;
}