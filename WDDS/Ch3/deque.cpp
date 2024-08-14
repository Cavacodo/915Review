#include <bits/stdc++.h>
using namespace std;
typedef struct LinkedNode{
    int data;
    struct LinkedNode *next;
    struct LinkedNode *pre;
}Node;

typedef struct LinkedList{
    Node *head,*tail;
}List;

void InitDeque(List &L){
    Node *t = (Node*)malloc(sizeof(Node));
    t->pre = nullptr;
    t->next = nullptr;
    L.head = t;
    L.tail = t;
}

void addFirst(List &L,int x){
    Node *t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = L.head->next;
    t->pre = L.head;
    L.head->next = t;
    if(L.head == L.tail) L.tail = L.head->next;
}

void addLast(List &L,int x){
    if(L.head == L.tail) addFirst(L,x);
    else{
        Node *t = (Node*)malloc(sizeof(Node));
        t->data = x;
        t->next = nullptr;
        t->pre = L.tail;
        L.tail->next = t;
        L.tail = t;
    }
}

bool removeFirst(List &L,int &x){
    if(L.head == L.tail) return false;
    x = L.head->next->data;
    Node *tmp = L.head->next;
    L.head->next->next->pre = L.head;
    L.head->next = L.head->next->next;
    free(tmp);
    return true;
}

bool removeLast(List &L,int &x){
    if(L.head == L.tail) return false;
    x = L.tail->data;
    Node *tmp = L.tail;
    L.tail = L.tail->pre;
    free(tmp);
    L.tail->next = nullptr;
    return true;
}

int main()
{
    List l;
    InitDeque(l);
    addFirst(l,1);
    addFirst(l,2);
    addLast(l,0);
    int x;
    removeFirst(l,x);  
    removeLast(l,x);
    Node *p = l.head->next;
    while(p != nullptr){
        cout << p->data << endl;
        p = p->next;
    }
    return	0;
}