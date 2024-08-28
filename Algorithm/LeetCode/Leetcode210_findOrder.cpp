// 拓扑排序
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses,0); 
        for(auto &n : prerequisites){
            inDeg[n[0]]++;
        }
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) if(inDeg[i] == 0) dq.push_back(i);
        int pre = -1;
        while(!dq.empty()){
            int t = dq.front();
            if(pre == t) return vector<int>();
            ans.push_back(t);
            pre = t;
            dq.pop_front();
            for(auto &n : prerequisites){
                if(n[1] == t){
                    inDeg[n[0]]--;
                    if(inDeg[n[0]]==0) dq.push_back(n[0]);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};