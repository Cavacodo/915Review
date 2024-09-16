// 递归实现二分查找
#include <bits/stdc++.h>
using namespace std;
int binary_search_recursive(vector<int> &n,int target,int l,int r){
    int mid = l + r >> 1;
    if(n[mid] == target) return mid;
    else if(n[mid] < target) return binary_search_recursive(n,target,mid+1,r);
    else  return binary_search_recursive(n,target,l,mid-1);
}
int main()
{
    vector<int> n = {1,2,4,6,1,2,4,9,4,1,2};
    sort(n.begin(),n.end());
    for(auto &i:n) cout << i << "\t";
    cout << endl;
    cout << binary_search_recursive(n,9,0,n.size()-1) << endl;
    return	0;
}