// 判断一年的哪一天
#include <bits/stdc++.h>
using namespace std;

int year,month,day;
vector<int> days_per_month = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int yr){
    return !yr % 400 || (!(yr % 4) && year % 100);
}
int whichDay(){
    if(isLeapYear(year)) days_per_month[2] = 29;
    int ans = 0;
    for(int i = 1; i < month; i++) ans += days_per_month[i];
    ans += day;
    return ans;
}
int main()
{
    cout << "Year:" << endl;
    cin >> year;
    cout << "Month:" << endl;
    cin >> month;
    cout << "Day:" <<endl;
    cin >> day;
    cout << "is the " << whichDay() << "th day" << endl;
    return	0;
}