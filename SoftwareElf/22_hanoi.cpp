#include <bits/stdc++.h>
using namespace std;
int n;

void move(char get,int n,char put){
    static int k = 1;
    // k是步数计数器
    cout << "第" << k  << "步将编号为" << n << "的盘子从" <<  get << "移动到" << put << endl;
    if(k++ % 3 == 0) cout << endl;
}
// hanoi函数的作用就是借助b将a上所有的圆盘移动到c
// 移动时这样想：
// 每次我只需要将n-1个圆盘从a移动到b，然后将剩下一个圆盘移动到c
// 最后将b上n-1个圆盘移动到c就行了
// 关于具体怎么实现的，就是借助递归划分子问题
// 移动4个圆盘要借助移动3个圆盘的思想
// 3个要借助2个的移动方法
// 2个借助一个
// 依次递归
void hanoi(int n,char a,char b,char c){
    if(n == 1)
        move(a,1,c);
    else{
        hanoi(n-1,a,c,b);
        move(a,n,c);
        hanoi(n-1,b,a,c);
    }
}

int main()
{
    cin >> n;
    hanoi(n,'X','Y','Z');
    return	0;
}