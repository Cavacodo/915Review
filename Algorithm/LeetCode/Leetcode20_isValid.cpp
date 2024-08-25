//括号匹配 栈的使用
//一生之耻了属于是
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        deque<char> dq;
        unordered_map<char,char> map;
        map['('] = ')';
        map['['] = ']';
        map['{'] = '}';
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(map.count(s[i])) dq.push_back(s[i]);
            else{
                if(dq.empty() || map[dq.back()] != s[i]) return 0;
                dq.pop_back();
            }
        }
        return dq.size() == 0;
    }
};

int main()
{
    
    
    return	0;
}