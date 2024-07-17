#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> umap;

    //umap初始化还可以直接赋值
    unordered_map<int,int> umap2 = {{1,2},{2,3},{1,3}};
    cout << umap2.size() <<endl;
    //初始化大小
    unordered_map<int,int> umap3(10);
    
    //插入元素方法
    umap.insert({1,2});
    umap.insert({2,3});
    umap.insert({3,4});
    umap[4] = 5;    //这样也可以
    //遍历元素
    cout << "元素遍历" << endl;
    for(auto it = umap.begin(); it != umap.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    cout << "删除元素" << umap.erase(2) << endl;
    //取出元素
    cout << umap[1] << endl;
    return	0;
}