#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> uset;
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(40);
    cout << "uset大小为" << uset.size() << endl;

    cout << "uset按序打印（乱序）" << endl;
    for(int i : uset){
        cout << i << " ";
    }

    cout << "查找在不在队列中" << endl;
    if(uset.find(10) != uset.end()){
        cout << "在集合中" << endl;
    }else{
        cout << "不在" << endl;
    }

    //删除元素
    cout << "删除元素" << endl;
    uset.erase(10);
    for(int i : uset){
        cout << i << " ";
    }
    return	0;
}