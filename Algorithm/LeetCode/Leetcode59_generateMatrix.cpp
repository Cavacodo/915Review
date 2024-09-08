#include <bits/stdc++.h>
using namespace std;

// 模拟
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int h = 0, v = 0;
        int cnt = 1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(cnt <= n*n){
            while(v < n && !ans[h][v]) ans[h][v++] = cnt++;
            v--;
            h++;
            while(h < n && !ans[h][v]) ans[h++][v] = cnt++;
            h--;
            v--;
            while(v >= 0 && !ans[h][v]) ans[h][v--] = cnt++;
            v++;
            h--;
            while(h >= 0 && !ans[h][v]) ans[h--][v] = cnt++;
            h++; 
            v++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t = sol.generateMatrix(3);
    return	0;
}