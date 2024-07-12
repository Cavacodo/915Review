#include <bits/stdc++.h>
#define N 1000
using namespace std;

int M;
int p[N];

int main(){
    cout << "数组个数" << endl;
    cin >> M;
    int idx = 0;
    cout << "输入数组，用空格隔开;" << endl;
    while(M--){
        cin >> p[idx++];
    }
    if(idx == 1 || idx == 0){
        cout << "出错" << endl;
        return -1;
    }
    int lastEle = p[idx - 1];
    int min = 0x7fffffff;
    int minIdx= idx;
    while(idx--){
        if(min >= p[idx]){
            min = p[idx];
            minIdx = idx;
        }
    }
    return 0;
}