// 判断完全平方数
// 二分
// 暴力
#include <bits/stdc++.h>
using namespace std;
// 暴力
class Solution1 {
public:
    long long g = 1;
    bool isPerfectSquare(int num) {
        while(g * g < num){
            g += 1;
        }
        return g * g == num;
    }
};
// 暴力的dfs写法
class Solution2 {
public:
    long long g = 1;
    bool isPerfectSquare(int num) {
        if(g * g == num) return 1;
        if(g * g < num){
            g += 1;
            return isPerfectSquare(num);
        }
        return 0;
    }
};

// 二分写法
class Solution3 {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num;
        long sq;
        while(l <= r){
            long mid = l + r >> 1;
            sq = mid * mid;
            if(sq == num) return 1;
            else if(sq < num) l = mid + 1;
            else{
                r = mid - 1;
            }
        }
        return 0;
    }
};

int main()
{
    
    
    return	0;
}