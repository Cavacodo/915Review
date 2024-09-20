#include <bits/stdc++.h>
using namespace std;

// m台机器，n个作业
int m,n; 
vector<int> times;

void process(){
    if(m > n){
        cout << "Arrangement is not important" << endl;
        return;
    }
    sort(times.begin(),times.end(),[](int a,int b){
        return a > b;
    });
    cout << "依次处理：" << endl;
    for(int i = 0; i < n; i++){
        cout << times[i] << endl;
    }
    return;

}

int main()
{
    cin >> m >> n;
    int t = n;
    while(t--){
        int a;
        // 输入作业处理需要时间
        cin >> a;
        times.push_back(a);
    }
    process();
    return	0;
}