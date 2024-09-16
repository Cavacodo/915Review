#include <bits/stdc++.h>
#define InitHeight 100.0
using namespace std;

vector<double> getHeight(int times){
    int sum = 0;
    double height = InitHeight;
    for(int i = 1; i < times; i++){
        sum += height * 1.5;
        height /= 2;
    }
    sum += height;
    height /= 2;
    vector<double> ans;
    ans.push_back(sum);
    ans.push_back(height);
    return  ans;
}

int main()
{
    cout << getHeight(2)[0] << endl;
    cout << getHeight(2)[1] << endl;
    return	0;
}