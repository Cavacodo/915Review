#include <bits/stdc++.h>
using namespace std;

void reverseQueue(deque<int> &dq){
    stack<int> st;
    while(!dq.empty()){
        int i = dq.front();
        st.push(i);
        dq.pop_front();
    }
    while(!st.empty()){
        int i = st.top();
        st.pop();
        dq.push_back(i);
    }
}

int main()
{
    deque<int> dq = {1,2,3,4,5};
    reverseQueue(dq);
    while(!dq.empty()){
        cout << dq.front() << "\t";
        dq.pop_front();
    }
    cout << endl;
    return	0;
}