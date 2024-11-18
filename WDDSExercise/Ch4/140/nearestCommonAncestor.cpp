#include <bits/stdc++.h>
using namespace std;

#define N 100010

vector<int> v;

int findCommonAncestor(int i,int j){
    while(1){
        if(i == j) return v[i];
        else if(i > j) i /= 2;
        else j /= 2;
    }
    return -1;
}

int main()
{
    v = {0,1,2,3,4,5,6,7,8,9,10};
    cout << findCommonAncestor(4,9) << endl;
    return	0;
}