#include <bits/stdc++.h>
using namespace std;

// O(logn)不应该只考虑二分搜索
// dfs树形暴搜
int n;
vector<int> arr;
vector<int> v;

struct Pair{
    int x,y;
};

void dfs(int l,int r,int k){
    if(l > r) return;
    int mid = l + r >> 1;
    if(arr[mid] < k) v.push_back(arr[mid]);
    dfs(mid+1,r,k);
    dfs(l,mid-1,k);
}

vector<Pair> findReversionPair(){
    vector<Pair> ans;
    for(int i = 0; i < arr.size()-1; i++){
        dfs(i+1,arr.size()-1,arr[i]);
        for(auto &t : v){
            Pair p = {arr[i],t};
            ans.push_back(p);
        }
        v.clear();
    }
    return ans;
} 
int main()
{
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    vector<Pair> ans = findReversionPair();
    return	0;
}