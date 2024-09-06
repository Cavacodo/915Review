// 划分一个数组为两个数组，要求元素数量差最小同时，两个数组的和之差最大
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<vector<int>> divide(vector<int> &v){
    int sum = 0;
    for(auto &i : v) sum += i;
    int n = v.size();
    sort(v.begin(),v.end());
    int mid = n / 2;
    vector<int> v1;
    vector<int> v2;
    if(n % 2){
        int l = 0, r = 0;
        for(int i = 0; i < mid; i++){
            l += v[i];
            v1.push_back(v[i]);
            v2.push_back(v[v.size()-1-i]);
        }
        r = sum - v[mid] - l;
        if(abs(r+v[mid]-l) >= abs(r-v[mid]-l)){
            v2.push_back(v[mid]);
        }else{
            v1.push_back(v[mid]);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }else{
        for(int i = 0; i < mid; i++){
            v1.push_back(v[i]);
            v2.push_back(v[v.size()-1-i]);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
    return ans;
}

int main()
{
    vector<int> v = {3,4,6,1,2,4,9};
    divide(v);
    return	0;
}