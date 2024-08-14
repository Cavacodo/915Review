#include <bits/stdc++.h>
using namespace std;

//获取next数组，别想太难，背板子，注意序号问题
//是哪一位没有匹配上，跳到对应的next位置，c跳到b，是因为c没匹配上，从而跳转到对应上一个a下一个元素位置
//但是假如4号位置a没有匹配上，回到1还是匹配不上
void get_next(string s,int* next){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < s.length()){
        if(j == 0 || s[i-1] == s[j-1]){
            ++i;
            ++j;
            next[i] = j; 
        }else{
            j = next[j];
        }
    }
}

int index_KMP(string s,string t,int* next){
    int i = 1, j = 1;
    while(i <= s.length() && j <= t.length()){
        if(j == 0 || s[i-1] == t[j-1]){
            ++i;
            ++j;
        }else{
            //没匹配上，回去了。
            j = next[j];
        }
    }
    if(j > t.length()){
        return i - t.length() - 1;  //走到11去了，跳出循环 i 多走了一位，所以减去。
    }
    return 0;
}

//递归防止出现无用返回
void get_nextval(string s,int* nextval){
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < s.length()){
        if(j == 0 || s[i-1] == s[j-1]){
            ++i;
            ++j;
            if(s[i-1] != s[j-1]) nextval[i] = j;
            else{
                nextval[i] = nextval[j];
            }
        }else{
            j = nextval[j];
        }
    }
}

int main()
{
    string s1 = "abcac";
    string s2 = "ababcabcacbab";
    int next[10];
    get_next(s1,next);
    get_nextval(s1,next);
    int ans = index_KMP(s2,s1,next);
    cout << ans << endl;
    return	0;
}