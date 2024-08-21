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

void ShellSort(int *nums){
    int dk,i,j,sentinel;
    // dk是每次排序的步长
    for(dk = N/2; dk > 0; dk /= 2){
        // 这里思想感受一下
        for(i = dk; i < N; i++){
            if(nums[i] < nums[i - dk]){
                sentinel = nums[i];
                for(j = i - dk;j >= 0 && sentinel < nums[j]; j-=dk){
                    nums[j+dk] = nums[j];
                }
                nums[j+dk] = sentinel;
            }
        }
    }
}


int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    ShellSort(nums);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}