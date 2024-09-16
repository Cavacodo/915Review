#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
void getAll(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            vector<int> t;
            for(int k = 1; k < j; k++){
                if(i*i == j*j + k*k){
                    t.push_back(i);
                    t.push_back(j);
                    t.push_back(k);
                    v.push_back(t);
                } 
            }
        }
    }
}

int main()
{
    getAll(100);
    for(int i = 0; i < v.size(); i++){
        for(auto &a : v[i]) cout << a << "\t";
        cout << endl;
    }
    return	0;
}