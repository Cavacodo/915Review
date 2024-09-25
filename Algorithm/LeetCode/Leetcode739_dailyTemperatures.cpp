// 单调栈
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        deque<int> dq;
        vector<int> ans(len,0);
        dq.push_back(0);
        for(int i = 1; i < len; i++){
            deque<int> tdq;
            while(!dq.empty() && temperatures[i] > temperatures[dq.front()]){
                ans[dq.front()] = i - dq.front();
                dq.pop_front();
            }
            // 单调栈应该按照温度升序排序
            while(!dq.empty() && temperatures[i] > temperatures[dq.front()]){
                tdq.push_back(dq.front());
                dq.pop_front();
            }
            dq.push_front(i);
            while(!tdq.empty()){
                dq.push_front(tdq.back());
                tdq.pop_back();
            }
        } 
        return ans;
    }
};


// 灵茶山艾府的单调栈
// 不用来回倒，时间复杂度低
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int t = temperatures[i];
            while (!st.empty() && t >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};


int main()
{
    
    return	0;
}