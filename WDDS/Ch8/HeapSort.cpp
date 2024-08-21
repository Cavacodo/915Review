#include <bits/stdc++.h>
using namespace std;
#define N 100
int nums[N];
void Init(int* nums){
    for(int i = 0; i < N; i++) nums[i] = rand();
}
void showResult(int* res){
    for(int i = 0; i < N; i++) cout << res[i] << "  ";
    cout << endl; 
}



int main()
{
    Init(nums);
    showResult(nums);
    return	0;
}