#include <bits/stdc++.h>
using namespace std;
// TODO 不太想写了，逻辑又问题要改
struct Queue{
    stack<int> s1,s2;
    void EnQueue(int n){
        s2.push(n);
    }
    int Dequeue(){
        if(s1.empty()) return -1;
        int i = s1.top();
        s1.pop();
        return i;
    }
    bool isEmpty(){
        return s1.empty();
    }
    void showQueue(){
        vector<int> v;
        while(!s1.empty()){
            int i = s1.top();
            cout << i << "\t";
            v.push_back(i);
            s1.pop();
        }
        for(int i = v.size()-1; i >= 0; i--){
            s1.push(v[i]);
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