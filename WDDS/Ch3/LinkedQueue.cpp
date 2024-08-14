#include <bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

typedef struct ListQueue{
    LNode *front,*back;
}LQ;

void InitLQ(LQ &lq){
    LNode *t = (LNode*)malloc(sizeof(LNode));
    t->data = -1;
    lq.front = t;
    lq.back = t;
}
bool isEmpty(LQ &lq){
    if(lq.front == lq.back) return true;
    return false;
}
void offer(LQ &lq,int x){
    LNode *t = (LNode*)malloc(sizeof(LNode));
    t->data = x;
    t->next = nullptr;
    lq.back->next = t;
    lq.back = t;
    if(lq.front->data == -1) lq.front = lq.back;
}
bool poll(LQ &lq,int &x){
    if(lq.back == lq.front) return false;
    x = lq.front->data;
    lq.front = lq.front->next;
    return true;
}
int main()
{
    LQ lq;
    InitLQ(lq);
    offer(lq,1);
    offer(lq,2);
    offer(lq,3);
    int x = 6;
    poll(lq,x);
    LNode *t = lq.front;
    while(t != nullptr){
        cout << t->data << endl;
        t = t->next;
    }
    cout << x << endl;
    return	0;
}