#include <bits/stdc++.h>
using namespace std;
int y,m,d;
int day_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeap(int year){
    return (year % 4 == 0 && year % 400 != 0);
}

void calDays(){
    cin >> y >> m >> d;
    if(isLeap(y)) day_month[2] = 29;
    int cnt = 0;
    for(int i = 1; i < m; i++){
        cnt += day_month[i];
    }
    cnt += d;
    cout << cnt << endl;
}
int main()
{
    calDays();
    return	0;
}