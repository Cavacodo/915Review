#include <bits/stdc++.h>
using namespace std;
//TODO 这个题很考察观察满二叉树
// 最后退出的顺序是左->右->根
// 因为递归的顺序是左->右
// 每一次都会被
void pre2post(vector<int> v,int l,int r){
    int n = v[l];
    if(l + 1 <= r){
        l++;    //剔除根节点，最后终会被打印 这步的理解很关键
        pre2post(v,l,(l+r)/2);
        pre2post(v,(l+r)/2+1,r);
    }
    cout << n << "\t";
}
int main()
{
    vector<int> pre = {1,2,4,5,3,6,7};
    pre2post(pre,0,pre.size()-1);
    cout << endl;
    return	0;
}