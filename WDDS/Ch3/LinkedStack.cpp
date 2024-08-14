//TODO 链表相关学习
#include <bits/stdc++.h>
using namespace std;
typedef struct LinkedNode{
    int data;
    struct LinkedNode *next;
}Node;
typedef struct LinkedStack{
    Node head,tail,pre;
    int size;
}LiStack;
void InitStack(LiStack &LS){
    Node node;
    LS.size = 0;
    LS.head = node;
    LS.tail = node;
    LS.pre = node;
}
bool isEmpty(LiStack &LS){
    return LS.size == 0 ? true : false;
}
bool push(LiStack &LS,int &x){
    LS.pre = LS.tail;
    Node nxt = {x,NULL};
    LS.tail = nxt;
}
int main()
{
    
    
    return	0;
}