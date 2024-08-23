#include <bits/stdc++.h>
using namespace std;
int arr[] = {0,9,4,9,7,5,4,5,2,0,9};

void heapadjust(int a[],int k,int len){
    a[0] = a[k];
    for(int i = 2*k;i <= len; i*=2){
        if(i < len && a[i] < a[i+1]) i++;
        if(a[0] >= a[i]) break;
        else{
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}
void buildmaxheap(int a[],int len){
    for(int i = len/2; i > 0; i--) heapadjust(a,i,len);
}
void heapsort(int a[],int len){
    buildmaxheap(a,len);
    for(int i = len;i > 1; i--){
        swap(a[i],a[1]);
        for(auto i = 1; i <= 10; i++) cout << arr[i];
        cout << endl;
        heapadjust(a,1,i-1);
    }
}
int main()
{
    heapsort(arr,10);
    return	0;
}