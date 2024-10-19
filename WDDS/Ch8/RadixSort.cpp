#include <bits/stdc++.h>
using namespace std;
#define N 10
int nums[N];

void Init(int* nums){
    for(int i = 0; i < N; i++) nums[i] = rand() % 100;
}

void showResult(int* res){
    for(int i = 0; i < N; i++) cout << res[i] << "  ";
    cout << endl; 
}

int maxDigit(int* x){
    int maxNum = *max_element(x, x + N);
    int digit = 0;
    while (maxNum > 0) {
        maxNum /= 10;
        digit++;
    }
    return digit;
}

void radixsort(int* data, int n) //基数排序
{
    int d = maxDigit(data);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    radixsort(nums,N);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}