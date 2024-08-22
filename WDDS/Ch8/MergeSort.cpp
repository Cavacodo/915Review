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
void Merge(int* nums,int low,int mid,int high){
    int i,j,k;
    for(k = low; k < high; k++) tmp[k] = nums[k];
    // 快慢指针将小元素复制到前面去，大元素放在后面
    for(i = low, j = mid + 1, k = i; i <= mid && j < high; k++){
        if(tmp[i] < nums[j]) nums[k] = tmp[i++];
        else nums[k] = tmp[j++];
    }
    // 这两个仅有一个执行
    while(i <= mid) nums[k++] = tmp[i++];
    while(j < high) nums[k++] = tmp[j++]; 
}
void MergeSort(int* nums,int low,int high){
    if(low < high){
        int mid = (low + high) / 2;
        MergeSort(nums,0,mid);
        MergeSort(nums,mid + 1,high);
        Merge(nums,low,mid,high);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    MergeSort(nums,0,N);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}