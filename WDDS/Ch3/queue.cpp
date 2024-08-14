#include <bits/stdc++.h>
using namespace std;
#define MaxSize 50
//这里是循环队列，不是线性的
typedef struct{
    int data[MaxSize];
    int front,back;
}Queue;
void InitQueue(Queue &q){
    q.front = 0;
    q.back = 0;
}
bool isEmpty(Queue &q){
    return q.front == q.back;
}
bool isFull(Queue &q){
    return (q.back + 1) % MaxSize == q.front;
}
bool getSize(Queue &q){
    return (q.back + MaxSize - q.front) % MaxSize;
}
bool offer(Queue &q,int x){
    if(isFull(q)) return false;
    q.data[q.back] = x;
    q.back = (q.back + 1) % MaxSize;
    return true;
}
bool poll(Queue &q,int &x){
    if(isEmpty(q)) return false;
    x = q.data[q.front];
    q.front = (q.front + 1) % MaxSize;
    return true;
}

int main()
{
    Queue q;
    InitQueue(q);
    offer(q,1);
    offer(q,2);
    offer(q,3);
    while(!isEmpty(q)){
        int x;
        poll(q,x);
        cout << x << endl;
    }
    return	0;
}