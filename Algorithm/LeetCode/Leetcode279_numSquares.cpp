// 不难，动态规划
#include <bits/stdc++.h>
using namespace std;

// 打表，DP
class Solution {
public:
    int sum = 0;
    vector<int> dp;
    int numSquares(int n) {
        for(int i = 0; i * i <= n; i++) dp.push_back(i * i);
        vector<int> p(n+1,INT_MAX);
        p[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < dp.size(); j++){
                if(i - dp[j] >= 0){
                    p[i] = min(p[i],1 + p[i - dp[j]]);
                }
            }
        }
        return p[n];
    }
};

int main()
{
    
    
    return	0;
}