#include <bits/stdc++.h>
#define InitSize 10 //宏不能使用分号
using namespace std;

typedef struct{
    int *data;
    int MaxSize;
    int length;
}SeqList;

void InitList(SeqList &L){
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for(int i=0; i<L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

int main(){
    SeqList l;
    InitList(l);
    IncreaseSize(l,5);
    return 0;
}