#include <bits/stdc++.h>
using namespace std;

int ocd2ten(char *ch){
    // 这里注意下，不能使用sizeof计算char引用数组长度，返回的是指针所占的8字符，不是总长度
    int n = strlen(ch);
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        int t = ch[i] - '0';
        ans += pow(8,n-1-i) * t;
    }
    return ans;
}

int main()
{
    char ch[] = {'2','2','1','2'};
    cout << ocd2ten(ch) << endl;
    return	0;
}