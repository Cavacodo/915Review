#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        deque<char> dq;
        unordered_map<char,char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                dq.push_back(s[i]);
            }else{
                if(dq.empty()) return 0;
                if(map[s[i]] == dq.back()){
                    dq.pop_back();
                    continue;
                }else return 0;
            }
        }
        return dq.empty() ? 1 : 0;
    }
};

int main()
{
    
    
    return	0;
}