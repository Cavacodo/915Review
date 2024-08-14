#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100

typedef struct sharedStack{
    int front,back;
    int size;
    int data[MaxSize];
}ShStack;
void InitStack(ShStack &SS){
    SS.back = 100;
    SS.front = -1;
    SS.size = 0;
    for(int i = 0; i < MaxSize; i++){
        SS.data[i] = 0;
    }
}
bool isEmpty(ShStack &SS){
    if(SS.back == 100 && SS.front == -1) return 1;
    return 0;
}
bool isBackEmpty(ShStack &SS){
    return SS.back == 100 ? true : false;
}
bool isFrontEmpty(ShStack &SS){
    return SS.front == -1 ? true : false;
}
bool pushFront(ShStack &SS,int x){
    if(SS.back - SS.front > 1){
        SS.data[++SS.front] = x;
        SS.size++;
        return true;
    }
    return false;
}
bool pushBack(ShStack &SS,int x){
    if(SS.back - SS.front > 1){
        SS.data[--SS.back] = x;
        SS.size++;
        return true;
    }return false;
}
bool popBack(ShStack &SS,int &x){
    if(SS.back < 100){
        x = SS.data[SS.back++];
        SS.size--;
        return true;
    }return false;
}
bool popFront(ShStack &SS,int &x){
    if(SS.front > -1){
        x = SS.data[SS.front--];
        SS.size--;
        return true;
    }return false;
}
bool peekFront(ShStack &SS,int &x){
    if(SS.front > -1){
        x = SS.data[SS.front];
        return true;
    }return false;
}
bool peekBack(ShStack &SS,int &x){
    if(SS.back < 100){
        x = SS.data[SS.back];
        return true;
    }return false;
}
int main()
{
    ShStack SS;
    InitStack(SS);
    pushBack(SS,1);
    pushFront(SS,3);
    pushBack(SS,9);
    pushFront(SS,100);
    int x = 0;
    popBack(SS,x);
    cout << x << endl;
    peekBack(SS,x);
    cout << x << endl;
    return	0;
}