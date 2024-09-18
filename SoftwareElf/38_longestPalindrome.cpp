#include <bits/stdc++.h>
using namespace std;

// 重点在怎么判断"aacabdkacaa" 这种情况
// 添加 i-dp[i][j] == len-j
class Solution {
public:
    string longestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(),rs.end());
        int len = s.size();
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        int mx = -1;
        int mxidx = 0;
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++){
                if(s[i-1] == rs[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > mx && i-dp[i][j] == len-j){
                    mx = dp[i][j];
                    mxidx = i;
                }
            }
        }
        return s.substr(mxidx-mx,mx);
    }
};

int main()
{
    string s = "abs";
    string rs = s;
    reverse(rs.begin(),rs.end());
    cout << s << "\t" << rs << endl;
    return	0;
}