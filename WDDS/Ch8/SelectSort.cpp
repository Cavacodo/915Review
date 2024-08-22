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

void SelectSort(int* nums){
    for(int i = 0; i < N-1; i++){
        int min = i;
        for(int j = i+1; j < N; j++){
            if(nums[j] < nums[min]) min = j;
        }
        if(min ^ i) swap(nums[i],nums[min]);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Init(nums);
    showResult(nums);
    SelectSort(nums);
    cout << "Sorted" << endl;
    showResult(nums);
    return	0;
}