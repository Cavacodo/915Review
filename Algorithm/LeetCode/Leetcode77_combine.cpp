//组合数
//学会怎么使用栈和递归
//注意每一层递归是使用start 还是 i
#include <bits/stdc++.h>
using namespace std;
class Solution {
vector<vector<int>> ans;
deque<int> dq;
void dfs(int n,int k,int start){
    if(dq.size() == k){
        ans.push_back(vector<int>(dq.begin(),dq.end()));    //vector存入deque
    }
    else{
        for(int i = start; i <= n-(k-dq.size()) + 1; i++){
            dq.push_back(i);
            dfs(n,k,i+1);   //  这里i+1 和 start+1 区别：i与层数无关 start与层数有关
            dq.pop_back();
        }
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,1);
        return ans;
    }
};

int main()
{
    
    
    return	0;
}