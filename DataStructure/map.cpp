#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> map;
    //插入元素
    map[1] = 10;
    map[2] = 20;
    map[3] = 30;
    map[1] = 40;

    //访问元素
    int val = map[3];

    cout << "map中的元素有" << map.size() << "个" << endl; 

    //遍历元素
    //auto关键字
    for(auto it = map.begin(); it != map.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    //auto2
    for(auto& pair : map){
        cout << pair.first << " " << pair.second << endl;
    }

    //查看某个key是否存在
    if(map.find(2) != map.end()){
        cout << "存在" << endl;
    }else{
        cout << "不存在" << endl;
    }
    //删除元素
    map.erase(1);

    //不提供keyset value方法
    return	0;
}