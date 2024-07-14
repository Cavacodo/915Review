#include <bits/stdc++.h>
using namespace std;

queue<int> a;

int main(){
    cout << "队列长度" << a.size() << endl; //队列长度
    cout << a.empty() << endl;  //判断是否为空
    // 添加元素
    a.push(7);
    a.push(8);
    //显示第一个元素:
    cout << "第一个元素" << a.front() <<endl;
    //显示最后一个元素:
    cout << "最后一个元素" << a.back() <<endl;
    //删除第一个元素
    a.pop();
    return 0;
}