#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main(){
    cout << s.size() << endl;
    s.push(6);
    s.push(8);
    cout << s.top() << endl;
    s.pop();    //  无返回值
    cout << s.empty() << endl;
    return 0;
}