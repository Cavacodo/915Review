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

void InserSort(int *nums){
    int i,j,sentinel;
    for(int i = 1; i < N; i++){
        if(nums[i] < nums[i-1]){
            sentinel = nums[i];
            // 二分查找
            // 找的是插入的位置
            int low = 0, high = i - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[mid] > sentinel) high = mid - 1;
                else low = mid + 1;
            }
            // high的最终位置就是目标下标
            // low此时大于high
            for(int j = i - 1; j >= high; j--)
                nums[j+1] = nums[j];
            nums[high+1] = sentinel;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    InserSort(nums);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}