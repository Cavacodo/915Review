#include <bits/stdc++.h>
using namespace std;
const int N = 10000;

unordered_map<int,vector<int>> umap;
unordered_map<int,int> upair;
void findDivisor(int n){
    vector<int> ans;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            sum += i;
        }
    }
    if(upair.count(sum)){
        cout << n << '\t';
        for(auto i : ans) cout << i << '\t';
        cout << endl;
        cout << upair[sum] << '\t';
        for(auto i : umap[sum]) cout << i << '\t';
        cout << endl;
    }else{
        umap[sum] = ans;
        upair[sum] = n;
    }
}

void findNum(){
    for(int i = 1; i < N; i++){
        findDivisor(i);
    }
}



int main()
{
    findNum();
    return	0;
}