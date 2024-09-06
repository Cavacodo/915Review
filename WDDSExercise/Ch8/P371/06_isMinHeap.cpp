// 判断一个数据序列是不是小根堆
#include <bits/stdc++.h>
using namespace std;
bool isMinHeap(vector<int> &v){
    for(int i = 0; i < v.size() / 2; i++){
        int root = v[i];
        if(v[i*2+2] >= root && v[i*2+1] >= root) continue;
        return false;
    }
    return true;
}
int main()
{
    vector<int> v = {9,17,53,32,45,65,78};
    cout << (int)isMinHeap(v) << endl;
    return	0;
}