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
            // 注意此处是从后往前遍历
            // 发生了值的改变
            for(j = i-1; nums[j] > sentinel && j >= 0; j--){
                nums[j+1] = nums[j];
            }
            // 注意此处的 j 可能已经不是原来的 i 而是前面的数字，因为发生了j--
            nums[j+1] = sentinel;
            // 这里什么情况都要使用 j+1 因为无论哪种情况，都是在 >= 时发生for跳出，所以加1
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