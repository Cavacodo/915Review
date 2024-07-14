#include <bits/stdc++.h>
using namespace std;

vector<int> vec1;       // 初始化一个长度为0的vec,和ArrayList一样
vector<int> vec2(5);    // 初始化一个长度为5的vec,每个元素初始化为0
vector<int> vec3(5, 1); // 初始化一个长度为5的vec,每个元素为1

static bool comp(const int &a, const int &b){  
    return a > b;
}   //  静态与否无所谓 返回 int 也行

int main()
{
    vec3.push_back(6);       // 尾部插入元素操作
    vec3.pop_back();         // 不穿入参数，删除尾部元素
    cout << vec3[3] << endl; // 直接访问对应位置的元素
    // vector操作中insert erase必须使用vec.begin(),vec.end()进行加减，不能使用整数。可以认为是一种格式
    vec3.insert(vec3.begin() + 2, 89); //  在下标为2的位置插入元素89，其余元素依次后移
    for (int i = 0; i < vec3.size(); i++)
    {
        cout << vec3[i] << endl;
    } // 1 1 89 1 1 1
    vec3.erase(vec3.begin() + 2);                 //  删除下标为2的元素，其余元素依次前移，此时为5个1
    vec3.erase(vec3.begin() + 1, vec3.end() - 2); // 清除下标为[1,3)区间的所有元素
    cout << "删除之后:" << endl;
    for (int i = 0; i < vec3.size(); i++)
    {
        cout << vec3[i] << endl;
    } // 1 1 1
    vec3.clear(); // size = 0

    // 借用algorithm库
    int t = 5;
    for (int i = 0; i < vec2.size(); i++)
        vec2[i] = t--;
    // vec2 = {5,4,3,2,1}
    reverse(vec2.begin(), vec2.end());
    // vec2 = {1,2,3,4,5}
    for (t; t < 5; t++)
        vec2[t] = rand();
    sort(vec2.begin(),vec2.end());  // 从小到大排序，可以指定位置 打断点自己看

    //重写排序函数
    sort(vec2.begin(),vec2.end(),comp);

    vector<vector<int>> vec4(5,vector<int>(5,8));   //创建一个5*5 元素均为8的矩阵
    return 0;
}