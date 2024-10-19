//逆序拓扑排序
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> inDeg;
vector<int> outDeg;
void Init(){
    
}
void reverseTopo(){
    deque<int> dq;
    for(int i = 0;i < outDeg.size(); i++){
        dq.push_back(i);
    }
    while(!dq.empty()){
        int tmp = dq.front();
    }
}
int main()
{
    
    return	0;
}