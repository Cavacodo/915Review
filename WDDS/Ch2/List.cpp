#include <bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode));  //创建头节点 类似于new
    L->next = nullptr;
    // ->是结构体指针，只能作为结构体的指针使用，L->next等价与(*L).next
    // L->next->data == ((*L).next).data
}
void Init(LinkList &L){
    LNode l = {-1,nullptr};
    L = &l;
}   //这样好像也行，但是要自己指定data和next域
int getLength(LinkList &L){
    int len = 0;
    LNode *p = L;
    while(p->next != NULL){
        len++;
        p = p->next;
    }
    return len;
}
bool headInsert(LinkList &L,int x){
    LNode *t = (LNode*)malloc(sizeof(LNode));
    t->data = x;
    t->next = L->next;
    L->next = t;
    return true;
}
int main()
{
    
    
    return	0;
}