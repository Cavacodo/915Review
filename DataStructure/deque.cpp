#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    deque<int> q{1,2,3,4,5}; //还可以直接初始化
    // 初始化元素为统一值
    q.assign(5,1);
    cout << "初始化后" << endl;
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << endl;
    }
    
    dq.push_back(0);
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(-1);
    // 直接通过直接访问遍历元素
    cout << "直接通过直接访问遍历元素" << endl;
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << endl;
    }
    dq.pop_back();
    dq.pop_front();
    
    //查看队列首部和尾部元素
    cout << "查看队列首部和尾部元素" << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    
    //查看是否为空
    cout << "队列是否为空：" << dq.empty() << endl;

    //清除所有元素
    dq.clear();
    return	0;
}