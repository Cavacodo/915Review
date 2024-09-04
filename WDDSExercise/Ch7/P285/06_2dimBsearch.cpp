// 二维二分搜索
#include <bits/stdc++.h>
using namespace std;
bool bsearch(vector<vector<int>> m,int target){
    int row = m.size();
    int col = m[0].size();
    int l = 0, r = col - 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(m[0][mid] == target) return true;
        else if(m[0][mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    int cl = l - 1;
    if(cl < 0) return false;
    l = 0, r = row - 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(m[mid][cl] == target) return true;
        else if(m[mid][cl] > target) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> m ={{1,4,7},{2,5,8},{3,6,9}};
    cout << bsearch(m,0) << endl;
    return	0;
}