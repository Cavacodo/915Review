// 输入5个数，递归倒叙输出
#include <bits/stdc++.h>
using namespace std;
void recursion_cout (int n){
    if(!n) return;
    else{
        int a;
        cin >> a;
        recursion_cout(n-1);
        cout << a << endl;
    }
}
int main()
{
    recursion_cout(5);
    return	0;
}