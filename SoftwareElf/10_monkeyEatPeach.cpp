#include <bits/stdc++.h>
using namespace std;

int getAll(int n,int res){
    for(int i = 1; i < n; i++){
        res = (res+1) * 2;
    }
    return res;
}
int main()
{
    cout << getAll(10,1) << endl;
    return	0;
}