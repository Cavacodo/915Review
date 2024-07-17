#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> set;
    //插入元素
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(1);

    //遍历元素
    cout << "元素有" << endl;
    for (int i : set)
    {
        cout << i << endl;
    }
    
    //数量查看
    cout << "元素数量" << endl;
    cout << set.size() << endl;
    cout << "是否为空" << endl;
    cout << set.empty() << endl;

    //查找元素
    //这里的逻辑是看查找指针有没有都遍历一遍然后是不是走到最后了
    if(set.find(2) != set.end()){
        cout << "在集合中" << endl;
    }else{
        cout << "没有" << endl;
    }
    
    //删除元素
    set.erase(1);
    return	0;
}