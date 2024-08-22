#include <bits/stdc++.h>
using namespace std;
#define N 10
int nums[N];
int tmp[N];
void Init(int* nums){
    for(int i = 0; i < N; i++) nums[i] = rand() % 10;
}
void showResult(int* res){
    for(int i = 0; i < N; i++) cout << res[i] << "  ";
    cout << endl; 
}
// 这里我们的数组长度和数字范围均为10以内
// len是原来数组的长度，k是数字的取值范围
void CountSort(int* nums,int* tmp,int len,int k){
    int i,C[k];
    for (int i = 0; i < k; i++) C[i] = 0;
    for (int i = 0; i < N; i++) C[nums[i]]++;   //记录等于的个数
    for (int i = 1; i < k; i++) C[i] += C[i-1]; //记录小于等于的个数
    for (int i = N-1; i >= 0; i--)
    {
        tmp[C[nums[i]] - 1] = nums[i];
        C[nums[i]] = C[nums[i]] - 1;   //自己被使用了，所以数量减1
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    CountSort(nums,tmp,N,N);
    cout << " Sorted" << endl;
    showResult(tmp);
    return	0;
}