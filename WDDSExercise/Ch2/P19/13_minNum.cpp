#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &n,int i);
int getMinNum(vector<int> &n){
    int m = 1;
    while(1){
        if(!binary_search(n,m)) return m;
        m++;
    }
    return -1;
}
int binary_search(vector<int> &n,int i){
    int l = 0,r = n.size()-1;
    while(l <= r){
        int mid = l + r >> 1;
        if(n[mid] == i) return 1;
        else if(n[mid] > i){
            r = mid - 1;
        }else l = mid + 1;
    }
    return 0;
}

int main()
{
    vector<int> n = {-5,3,2,3};
    vector<int> m = {1,2,3};
    cout << getMinNum(n) << endl;
    cout << getMinNum(m) << endl;
    return	0;
}