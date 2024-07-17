#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(30);
    int a = pq.size();
    while (a--)
    {
        //访问堆顶元素
        cout << pq.top() << endl;
        //弹出不返回值
        pq.pop();
    }//打印50 30 10，默认大根堆，和Java不同
    

    struct compare
    {
        bool operator()(int a,int b){
            return a > b;   //小根堆
        }
    };
    
    //重新定义需要加上模版类型，默认vector,但是没有会报错
    priority_queue<int,vector<int>,compare> pq2;
    pq2.push(30);
    pq2.push(50);
    pq2.push(10);
    a = pq2.size();
    //改写之后
    cout <<  "改写之后" << endl;
    while(a--){
        cout << pq2.top() << endl;
        pq2.pop();
    }
    
    return	0;
}