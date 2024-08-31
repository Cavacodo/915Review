#include <bits/stdc++.h>
using namespace std;

void sameElement(vector<vector<int>> &seq){
    int n = seq[0].size();
    unordered_map<int,int> map;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            map[seq[i][j]]++;
            if(map[seq[i][j]] == 3){
                cout << seq[i][j] << endl;
            }
        }
    }
}

int main()
{
    vector<vector<int>> t = {{1,2,3,9},{3,4,5,9},{3,5,7,9}};
    sameElement(t);
    return	0;
}