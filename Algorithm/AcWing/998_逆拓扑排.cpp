#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> outDeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        outDeg.resize(numCourses);
        vector<int> reverse;
        for(auto& a : prerequisites){
            outDeg[a[0]]++;
            edges[a[1]].push_back(a[0]);
        }
        deque<int> dq;
        for(int i = 0; i < outDeg.size(); i++){
            if(outDeg[i] == 0) dq.push_back(i);
        }
        while(!dq.empty()){
            int t = dq.front();
            reverse.push_back(t);
            dq.pop_front();
            for(auto& i : edges[t]){
                --outDeg[i];
                if(outDeg[i] == 0) dq.push_back(i);
            }
        }
        return reverse.size() == numCourses;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> pre = {{0,1},{0,2},{1,3},{1,3}};
    sol.canFinish(4,pre);
    return	0;
}