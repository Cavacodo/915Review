#include <bits/stdc++.h>
using namespace std;

int m,n;

// 这里可以直接用string接，防止overflow
int statistic(){
    cin >> n >> m;
    if(n < 0 && n > 9){
        cout << "第二个参数越界" << endl;
        return -1;
    }
    string s = to_string(m);
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] - '0' == n) cnt++;
    }
    return cnt;
}

int main()
{
    cout << statistic() << endl;
    return	0;
}