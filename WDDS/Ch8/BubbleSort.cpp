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

void BubbleSort(int* nums){
    for(int i = 0; i < N-1; i++){
        bool flag = 0;
        // 从后往前，交换大小的元素
        for(int j = N-1; j > i; j--){
            if(nums[j-1] > nums[j]){
                swap(nums[j-1],nums[j]);
                flag = 1;
            }
        }
        if(!flag) return;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    BubbleSort(nums);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}