// 最小栈实现
// 常数时间实现最小值提取
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    deque<int> dq;
    deque<int> minDq;
    MinStack() {

    }
    
    void push(int val) {
        dq.push_back(val);
        if(minDq.empty() || minDq.back() >= val) minDq.push_back(val); 
    }
    
    void pop() {
        int t = dq.back();
        dq.pop_back();
        if(t == minDq.back()) minDq.pop_back();
    }
    
    int top() {
        return dq.back();
    }
    
    int getMin() {
        return minDq.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    
    return	0;
}