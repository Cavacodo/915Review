//两个队列模拟栈
#include <bits/stdc++.h>
using namespace std;

class MyStack {
deque<int> dq1;
deque<int> dq2;
public:
    MyStack() {

    }
    
    void push(int x) {
        dq1.push_back(x);
    }
    
    int pop() {
        while(dq1.size() > 1){
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        int ans = dq1.front();
        dq1.pop_front();
        while(!dq2.empty()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int top() {
        while(dq1.size() > 1){
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        int ans = dq1.front();
        dq2.push_back(ans);
        dq1.pop_front();
        while(!dq2.empty()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    bool empty() {
        return dq1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */