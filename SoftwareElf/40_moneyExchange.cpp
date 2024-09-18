// 贪心解决钱币找零问题
#include <bits/stdc++.h>
using namespace std;

int currency[] = {1,2,5,10,20,50,100};
int nums[] = {0,0,0,0,0,0,0};

int minMoney(int money){
    int cnt = 0;
    while(money > 0){
        for(int i = 6; i >= 0; i--){
            if(nums[i] > 0 && money >= currency[i]){
                int t = money / currency[i];
                nums[i] -= t;
                money -= t * currency[i];
                cnt += t;
            }
        }
    }
    return cnt;
}

int main()
{
    int n = 7;
    int cnt = 0;
    while(n--) cin >> nums[cnt++];
    cout << minMoney(1141) << endl;
    return	0;
}