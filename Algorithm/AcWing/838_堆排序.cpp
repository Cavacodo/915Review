#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
int n,m;
int sz;
int h[N];

void sift_down(int k){
    int t = k;
    // 注意这里使用k不是t，不然第二层if会发生改变
    if(k * 2 <= sz && h[k * 2] < h[t]) t = k * 2;
    if(k * 2 + 1 <= sz && h[k * 2 + 1] < h [t]) t = 2 * k + 1;
    if(t != k){
        swap(h[k],h[t]);
        sift_down(t);
    }
}

int main()
{
    cin >> n >> m;
    sz = n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = n/2; i ; i--) sift_down(i);
    while(m--){
        cout << h[1] << ' ';
        h[1] = h[sz];
        sz--;
        sift_down(1);
    }
    cout << endl;
    return 0;
}