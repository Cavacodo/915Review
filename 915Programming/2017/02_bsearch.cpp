#include <bits/stdc++.h>
using namespace std;

int Binsearch(vector<int> &v,int low,int high,int k){
    while(low <= high){
        int mid = low + high >> 1;
        if(v[mid] == k) return mid;
        else if(v[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    
    return	0;
}