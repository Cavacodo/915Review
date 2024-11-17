#include <bits/stdc++.h>
using namespace std;

const int N = 100010;


typedef struct minStack{
    int st1[N];
    int ast[N];
    int stp1 = -1, astp = -1;
    void push(int x){
        st1[++stp1] = x;
        if(astp == -1 || x <= ast[astp]){
            ast[++astp] = x;
        }
    }
    void pop(){
        if(stp1 <= 0){
            cout << "空指针" << endl;
            return;
        }else{
            // cout << st1[stp1] << endl;
            if(ast[astp] == st1[stp1]){
                astp--;
            }
            stp1--;
        }
    }
    int getMin(){
        return ast[astp];
    }
};

int main()
{
    minStack ms;
    ms.push(1);
    ms.push(6);
    ms.push(9);
    ms.push(4);
    cout << ms.getMin() << endl;
    ms.push(-1);
    ms.pop();
    ms.pop();
    cout << ms.getMin() << endl;
    return	0;
}