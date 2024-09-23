// 前缀和好题
#include <bits/stdc++.h>
using namespace std;

// 条件比较难想但是这个题很好
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, s = 0;
        unordered_map<int, int> pos;
        for (int i = 0; i < hours.size(); ++i) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                ans = i + 1;
            } else if (pos.count(s - 1)) {
                ans = max(ans, i - pos[s - 1]);
            }
            if (!pos.count(s)) {
                pos[s] = i;
            }
        }
        return ans;
    }
};



int main()
{
    vector<int> h = {6,9,9};
    Solution sol;
    sol.longestWPI(h);
    return	0;
}