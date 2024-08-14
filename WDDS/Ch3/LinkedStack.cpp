#include <bits/stdc++.h>
using namespace std;
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LiNode,*List;

void InitLink(List &L){
    L = (LiNode*)malloc(sizeof(LiNode));
    L->next = nullptr;
}

void push(List &L,int x){
    LiNode *target = (LiNode*)malloc(sizeof(LiNode));
    target->data = x;
    target->next = L->next;
    L->next = target;
}

bool pop(List &L,int &x){
    if(L->next == nullptr) return false;
    x = L->next->data;
    L->next = L->next->next;
    return true;
}
 
int main(){
    List L;
    InitLink(L);
    push(L,1);
    push(L,2);
    push(L,3);
    int x;
    pop(L,x);
    // cout << x << endl;
    LiNode *cur = L->next;
    while(cur != nullptr){
        cout << cur->data << endl;
        cur = cur->next;
    }
    return 0;
}