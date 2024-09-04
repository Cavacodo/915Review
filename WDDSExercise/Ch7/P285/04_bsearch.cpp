#include <bits/stdc++.h>
using namespace std;

int bsearch(vector<int> v,int target){
    int l = 0, r = v.size() - 1;
    int mid;
    while(l <= r){
        mid = l + r >> 1;
        if(v[mid] == target) return mid;
        else if(v[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
}
int main()
{
    vector<int> v = {1,2,3,4,5,6,6};
    int target = 5;
    cout << bsearch(v,target) << endl;
    return	0;
}