// Bruteforce 字符串匹配算法
// 说白了就是暴力匹配
#include <bits/stdc++.h>
using namespace std;

int BruteForce(string s, string pattern){
    int n = s.size();
    int m = pattern.size();
    int i = 0, j = 0;
    while(i < n && j < m){
        while(pattern[j] == s[i]){
            j++;
            i++;
            if(j == m) return i - m;
        }
        i++;
    } 
    return -1;
}
int main()
{
    string a = "abababac";
    string b = "bac";
    cout << BruteForce(a,b) << endl;
    return	0;
}