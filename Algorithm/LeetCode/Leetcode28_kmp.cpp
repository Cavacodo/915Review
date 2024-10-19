#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> get_next(string p){
        vector<int> next(p.size(),0);
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < p.size(); i++){
            while(j > 0 && p[j] != p[i]) j = next[j-1];
            if(p[i] == p[j]) j++;
            next[i] = j;
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        vector<int> next = get_next(needle);
        // 向后整体移动一位
        int tmp = next[0];
        for(int i = 1; i < next.size(); i++){
            int t = next[i];
            next[i] = tmp;
            tmp = t;
        }
        next[0] = -1;
        vector<int> nextval(needle.size(),0);
        nextval[0] = next[0];
        for(int i = 1; i < needle.size(); i++){
            if(needle[i] != needle[next[i]]) nextval[i] = next[i];
            else nextval[i] = nextval[next[i]];
        }
        int hp = 0, np = 0;
        while(hp < haystack.size()){
            if(haystack[hp] == needle[np]){
                ++hp;
                ++np;
                if(np == needle.size()) return hp-np;
            }else{
                if(nextval[np] == -1){
                    np = 0;
                    ++hp;
                    continue;
                }
                np = nextval[np];
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "aabaaabaaac";
    string needle = "abaabcaba";
    sol.strStr(haystack,needle);
    return	0;
}