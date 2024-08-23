#include <bits/stdc++.h>
#define N 1000
using namespace std;

typedef struct
{
    int arr[N];
    int size;
} linearlist;

int M;

void init(linearlist &ll)
{
    ll.size = 0;
}

bool add(linearlist &ll, int val)
{
    if (ll.size < N)
    {
        ll.arr[ll.size] = val;
        ll.size++;
        return true;
    }
    return false;
}

int deleteMinVal(linearlist &ll)
{
    int size = ll.size;
    if (size == 1 || size == 0)
    {
        cout << "错误" << endl;
        return -1;
    }
    int min = 0x7fffffff;
    int minIdx = 0;
    int lastVal = ll.arr[size - 1];
    while (size--)
    {
        if (min > ll.arr[size])
        {
            min = ll.arr[size];
            minIdx = size;
        }
    }
    ll.arr[minIdx] = lastVal;
    ll.size--;
    return min;
}

int main()
{
    cout << "数组元素个数" << endl;
    cin >> M;
    int idx = 0;
    cout << "输入数组，用空格隔开;" << endl;
    linearlist ll;
    init(ll);
    while (M--)
    {
        int tmp;
        cin >> tmp;
        add(ll, tmp);
    }
    int l = ll.size;
    cout << "初始化的ll数组" << endl;
    for (int i = 0; i < l; i++)
        cout << ll.arr[i] << " ";
    int ans = deleteMinVal(ll);
    l = ll.size;
    cout << "处理后的的ll数组" << endl;
    for (int i = 0; i < l; i++)
        cout << ll.arr[i] << " ";
    cout << endl;
    cout << "被删除的元素是:" << ans << endl;
    return 0;
}