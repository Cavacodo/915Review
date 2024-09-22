#include <bits/stdc++.h>
using namespace std;

vector<int> pnumber;

int getFactorSum(int x){
    int sum = 0;
    for(int i = 1; i <= x/2; i++){
        if(x % i == 0){
            sum += i;
        }
    }
    return sum;
}

void getThousandPerfect(){
    for(int i = 1; i <= 10000; i++){
        if(getFactorSum(i) == i){
            pnumber.push_back(i);
            cout << i << '\t';
        }
    }
    cout << endl;
}

int getP4PerfectNumber(int x){
    // 计算公式满足 2t*t - t = pnumber
    // t = 2^(p-1)
    int t = (1 + sqrt(1+4*2*x)) / 4;
    return log(t) / log(2) + 1;
}
int main()
{
    getThousandPerfect();
    for(auto &i : pnumber){
        cout << getP4PerfectNumber(i) << '\t' << i << endl;
    }
    return	0;
}