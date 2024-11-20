#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1,vector<int> v2){
    vector<int> ans;
    int l1 = v1.size() , l2 = v2.size();
    int p1 = 0, p2 = 0;
    while(p1 < l1 && p2 < l2){
        while(p1 < l1 && v1[p1] <= v2[p2]){
            ans.push_back(v1[p1++]);
        }
        while(p2 < l2 && v2[p2] <= v1[p1]){
            ans.push_back(v2[p2++]);
        }
    }
    while(p1 < l1) ans.push_back(v1[p1++]);
    while(p2 < l2) ans.push_back(v2[p2++]);
    return ans;
}

vector<int> selectOrder(vector<vector<int>> arr){
    vector<int> ans;
    int n = arr.size();
    vector<int> tmp;
    for(auto& i : arr) tmp.push_back(i.size());
    while(tmp.size() > 1){
        sort(tmp.begin(),tmp.end());

        tmp.push_back(tmp[1] + tmp[2]);
        tmp.erase(tmp.begin() + 2);
    }
} 

int main()
{
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {3,4,5,6,7,8};
    vector<int> ans = merge(v1,v2);
    return	0;
}