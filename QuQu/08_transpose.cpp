#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &v){
    int len = v.size();
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            swap(v[i][j],v[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1,2,3},
                             {4,5,6},
                             {7,8,9}};
    transpose(v);
    return	0;
}