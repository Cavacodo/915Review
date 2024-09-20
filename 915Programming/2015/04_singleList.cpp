#include <bits/stdc++.h>
using namespace std;

struct Lnode{
    int data;
    struct Lnode *next;
    Lnode() : data(0) ,next(nullptr) {}
    Lnode(int x) : data(x) , next(nullptr) {}
};

int fun(struct Lnode* hl,int x){
    Lnode* cur = hl;
    int cnt = 0;
    while(cur != nullptr){
        if(cur->data == x) cnt++;
        cur = cur->next;
    }
    return cnt;
}

int main()
{
    Lnode* head = new Lnode();
    head->next = new Lnode(3);
    head->next->next = new Lnode(4);
    head->next->next->next = new Lnode(5);
    head->next->next->next->next = new Lnode(3);
    cout << fun(head,3) << endl;
    return	0;
}