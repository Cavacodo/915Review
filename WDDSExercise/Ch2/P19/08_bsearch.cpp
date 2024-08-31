#include <bits/stdc++.h>
using namespace std;

void binary_search(vector<int> &arr,int num){
    int l = 0, r = arr.size()-1;
    bool flag = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(arr[mid] == num){
            swap(arr[mid],arr[mid+1]);
            flag = 1;
            break;
        }else if(arr[mid] < num){
            l = mid + 1;
        }else r = mid - 1;
    }
    if(!flag) arr.insert(arr.begin()+l,num);
}

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8};
    binary_search(a,-1);
    for(auto i : a) cout << i << "\t";
    cout << endl;
    return	0;
}