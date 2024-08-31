#include <bits/stdc++.h>
using namespace std;
vector<int> getMinTriDistance(vector<int> v1,vector<int> v2,vector<int> v3){
    vector<int> ans(3,0);
    int m = INT_MAX;
    for(int i = 0; i < v1.size(); i++){
        int j = 0,k = 0;
        int x = INT_MAX,y = INT_MAX;
        while(j < v2.size() && abs(v1[i]-v2[j]) < x){
            x = abs(v1[i]-v2[j]);
            j++;
        }
        while(k < v2.size() && abs(v1[i]-v3[k]) < y){
            y = abs(v1[i]-v3[k]);
            k++;
        }
        if(x+y+abs(v2[j-1]-v3[k-1]) < m){
            ans[0] = v1[i];
            ans[1] = v2[j-1];
            ans[2] = v3[k-1];
            m = x+y+abs(v2[j-1]-v3[k-1]);
        }
    }
    return ans;
}
int main()
{
    vector<int> v1 = {-1,0,9};
    vector<int> v2 = {-25,-10,10,11};
    vector<int> v3 = {2,9,17,30,41};
    for(auto i : getMinTriDistance(v1,v2,v3)) cout << i << "\t";
    cout << endl;
    return	0;
}