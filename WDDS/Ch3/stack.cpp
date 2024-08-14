#include <bits/stdc++.h>
using namespace std;
#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;
//初始化
void InitStack(SqStack &S){
    S.top = -1;
}
bool isEmpty(SqStack S){
    return S.top == -1;
}
//入栈
bool push(SqStack &S,int x){
    if(S.top == MaxSize - 1) return false;
    S.data[++S.top] = x;
    return true;
}
bool pop(SqStack &S,int &x){
    if(S.top == -1) return false;
    x = S.data[S.top--];    //此处为了返回一个栈顶元素使用引用形式返回
    return true;
}
bool peek(SqStack &S,int &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    return true;
}
int main()
{
    SqStack sq;
    InitStack(sq);
    push(sq,1);
    push(sq,2);
    push(sq,3);
    int t = 0;
    pop(sq,t);
    cout << t << endl;
    peek(sq,t);
    cout << t << endl;    
    return	0;
}