#include <bits/stdc++.h>
using namespace std;

int getMainElement(vector<int> &n){
    unordered_map<int,int> map;
    for(int &i : n){
        map[i]++;
        if(map[i] > n.size()/2) return i;
    }
    return -1;
}

int main()
{
    vector<int> n = {0,5,5,3,5,7,5,5};
    vector<int> m = {0,5,5,3,5,1,5,7};
    cout << getMainElement(n) << endl;
    cout << getMainElement(m) << endl;
    return	0;
}