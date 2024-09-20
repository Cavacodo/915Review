#include <bits/stdc++.h>
using namespace std;

bool isPalindrome_non_recursive(string &s){
    int len = s.size();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-1-i]) return false;
    }
    return true;
}

bool isPalindrome_recursive(string &s,int l,int r){
    if(l >= r) return true;
    return s[l] == s[r] ? isPalindrome_recursive(s,l+1,r-1) : false; 
}

bool isPalindrome_using_stack(string &s){
    deque<char> dq;
    for(int i = 0; i < s.size(); i++) dq.push_back(s[i]);
    for(int i = 0; i < s.size()/2; i++){
        char t = dq.back();
        dq.pop_back();
        if(s[i] != t) return false;
    }
    return true;
}

int main()
{
    string s = "abccbab";
    cout << (int)(isPalindrome_using_stack(s)) << endl;
    return	0;
}