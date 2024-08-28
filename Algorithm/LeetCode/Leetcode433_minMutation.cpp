//DFS
//BFS
//dp?
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
private:
    int minNum = INT_MAX,num = 0;
    unordered_set<string> set;
public:
    int minMutation(string start, string end, vector<string>& bank) {
        /* 递归截止条件 计算最小变化次数 */
        if(start == end) {
            minNum = min(num, minNum);
            return minNum;
        }
        for(string& str : bank) {
            int diff = 0;
            for(int i = 0; i < str.size(); i++)
                if(str[i] != start[i]) diff++;
            /* 比较是否相差一个字母 以及用set去重 */
            if(diff == 1 && set.find(str) == set.end()) {
                    set.insert(str);
                    num += 1;
                    minMutation(str, end, bank);
                    num -= 1;       // 回溯，次数减1
                    set.erase(str); // 回溯，删除字符串
            }
        }
        return minNum == INT_MAX ? -1 : minNum;
    } 
};


int main()
{
    
    
    return	0;
}