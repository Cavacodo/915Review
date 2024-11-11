#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int pa[N];
int nums[N];

int find(int x){
    if(pa[x] != x){
        pa[x] = find(pa[x]);
    }
    return pa[x];
}

int main()
{
    for(int i = 0 ; i < N; i++){
        pa[i] = i;
        nums[i] = 1;
    }
    int n,m;
    cin >> n >> m;
    while (m -- ){
        string s;
        int a,b;
        cin >> s;
        if(s == "C"){
            cin >> a >> b;
            if(find(a) == find(b)) continue;    // 如果已经在一个集合中，就不要重复操作，修改nums了
            nums[find(a)] += nums[find(b)];
            pa[find(b)] = find(a);
        }else if(s == "Q1"){
            cin >> a >> b;
            if(find(a) == find(b)){
                cout << "Yes" << endl;
            }else cout << "No" << endl;
        }else{
            cin >> a;
            cout << nums[find(a)] << endl;
        }
    }
    return 0;
}