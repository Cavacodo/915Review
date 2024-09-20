#include <bits/stdc++.h>
#define N 1010
using namespace std;


typedef struct SeqStack{
    int size = 0;
    int hp = -1, tp = -1;
    int st[N];
    SeqStack(int n) : size(n) , tp(n) {}
    int push_front(int x){
        if(hp >= tp-1) return -1;
        st[++hp] = x;
        return 0;
    }
    int push_back(int x){
        if(tp <= hp+1) return -1;
        st[--tp] = x;
        return 0;
    }
    int poll_front(){
        if(hp < 0) return -1;
        return st[hp--];
    }
    int poll_back(){
        if(tp >= size) return -1;
        return st[tp++];
    }
    int getSize_front(){
        return hp+1;
    }
    int getSize_back(){
        return size-tp;
    }
}dual_stack;


int main()
{
    dual_stack* ds = new dual_stack(10);
    ds->push_back(1);
    ds->push_front(2);
    cout << ds->getSize_back();
    return	0;
}