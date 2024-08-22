#include <bits/stdc++.h>
#define N 10
using namespace std;
// 二分模版
int nums[N];
void Init(int* nums){
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < N; i++) nums[i] = rand() % 10;
}
void showResult(int* res){
    for(int i = 0; i < N; i++) cout << res[i] << "  ";
    cout << endl; 
}
// <=时，使用 > (high = mid - 1) < (low = mid + 1)
// 双闭区间[]
int binary_search(int* nums,int k){
    int low = 0, high = N-1,mid;
    while(low <= high){ //闭区间使用mid + 1 mid - 1 防止陷入死循环
        mid = (low + high) >> 1;
        if(nums[mid] == k) return mid;
        else if(nums[mid] > k) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
// https://www.acwing.com/blog/content/31/
// https://imageslr.com/2020/03/15/binary-search.html
// 灵茶山艾府的视频讲解： LeetCode 34
// https://www.bilibili.com/video/BV1AP41137w7/?spm_id_from=333.337.search-card.all.click&vd_source=bc351f6643e60f43d3232d2b424ded83
// 左闭右开
int binary_search2(int* nums,int k){
    int low = 0, high = N;
    while(low < high){
        int mid = (low + high) >> 1;
        if(nums[mid] < k) low = mid + 1;
        else high = mid;    //mid为闭区间的左
    }
    return low; //没找到就是大于该元素的第一个元素 high也行
}
// 开区间
int binary_search3(int* nums,int k){
    int low = -1, high = N, mid;
    while(low + 1 < high){ //low + 1 == high () low + 1 > high要么重合要么)(都是空
        mid = (low + high) >> 1;
        if(nums[mid] < k) low = mid;
        else high = mid;
    }
    return low; //只能是low )(情况出现 
}

int main()
{
    Init(nums);
    sort(nums,nums + N);
    showResult(nums);
    int ans = binary_search3(nums,7);
    cout << ans << endl;
    return	0;
}