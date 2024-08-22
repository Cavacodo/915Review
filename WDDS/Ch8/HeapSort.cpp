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
// 这里我们使用的堆是使用数组表示的，可以视为完全二叉树
// 大根堆
void HeapAdjust(int* nums,int k,int len){
    int sentinel = nums[k];
    for(int i = 2*k; i < len; i*=2){
        // 跳转大相邻的大的
        if(i < len-1 && nums[i] < nums[i+1]) i++;
        if(sentinel >= nums[i]) break;
        else{
            nums[k] = nums[i];
            k = i;  //下坠
        }
    }
    nums[k] = sentinel; // 太小被放在下面
}
void BuildMaxHeap(int* nums){
    // 这里一定要逆序，不然结果不对，因为先调整后面又调整了
    for(int i = N/2; i > 0; i--) HeapAdjust(nums,i,N);
}
void HeapSort(int* nums){
    BuildMaxHeap(nums);
    for(int i = N-1; i >= 0; i--){
        swap(nums[i],nums[0]);
        HeapAdjust(nums,0,i-1);
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    HeapSort(nums);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}
// TODO 有小Bug