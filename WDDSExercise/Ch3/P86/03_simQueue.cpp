#include <bits/stdc++.h>
using namespace std;
// TODO 不太想写了，逻辑又问题要改
struct Queue{
    stack<int> s1,s2;
    void EnQueue(int n){
        s2.push(n);
    }
    int Dequeue(){
        while(!s2.empty()){
            int i = s2.top();
            s1.push(i);
            s2.pop();
        }
        if(s1.empty()) return -1;
        int t = s1.top();
        s1.pop();
        while(!s1.empty()){
            int i = s1.top();
            s2.push(i);
            s1.pop();
        }
        return t;
    }
    bool isEmpty(){
        return s2.empty();
    }
    void showQueue(){
        vector<int> v;
        while(!s2.empty()){
            int i = s2.top();
            cout << i << "\t";
            v.push_back(i);
            s2.pop();
        }
        for(int i = v.size()-1; i >= 0; i--){
            s2.push(v[i]);
        }
        cout << endl;
    }
};


int main()
{
    Queue q;
    q.EnQueue(1);  
    q.EnQueue(2);
    q.EnQueue(10);
    q.EnQueue(3);
    q.showQueue();
    q.Dequeue();
    q.showQueue();
    cout << q.isEmpty() << endl;
    return	0;
}