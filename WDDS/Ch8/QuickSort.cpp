#include <bits/stdc++.h>
using namespace std;
#define N 10
int nums[N];
void Init(int* nums){
    for(int i = 0; i < N; i++) nums[i] = rand() % 10;
}
void showResult(int* res){
    for(int i = 0; i < N; i++) cout << res[i] << "  ";
    cout << endl; 
}

int Partition(int* nums,int low,int high){
    int pivot  = nums[low]; //可以是其他的元素
    while(low < high){
        while(low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while(low < high && nums[low] <= pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;  //这里其实使用high也可以
    return low;
}

void QuickSort(int *nums,int low,int high){
    if(low < high){
        int pivot = Partition(nums,low,high);
        QuickSort(nums,low,pivot-1);
        QuickSort(nums,pivot+1,high);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    QuickSort(nums,0,N-1);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}