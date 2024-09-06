// 找出第k小的元素 快排
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int low,int high){
    int pivot = v[low];
    while(low < high){
        // 从右向左找到小于pivot的第一个位置
        while(low < high && v[high] >= pivot) --high;
        v[low] = v[high];
        // 从左向右找到大雨pivot的第一个位置
        while(low < high && v[low] <= pivot) ++low;
        v[high] = v[low];
    }
    v[low] = pivot;
    return low; //pivot的最终位置
}
void QuickSort(vector<int> &v,int low,int high){
    if(low < high){
        int pivot = partition(v,low,high);
        QuickSort(v,low,pivot-1);
        QuickSort(v,pivot+1,high);
    }
}
int getMinK(vector<int> &v,int k){
    QuickSort(v,0,v.size()-1);
    return v[k-1];
}
int main()
{
    vector<int> v = {1,3,4,6,2,3,6};
    cout << getMinK(v,4) << endl;
    return	0;
}