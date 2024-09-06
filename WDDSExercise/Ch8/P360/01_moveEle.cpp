// 把线性表中的所有奇数移动到偶数前面
#include <bits/stdc++.h>
using namespace std;

void moveElement(vector<int> &v)
{
    int n = v.size();
    int l = 0, r = 0;
    while (l < n && r < n)
    {
        while (l < n)
        {
            if (!v[l] % 2)
                l++;
            else
                break;
        } // l 存储的是第一个奇数
        while (r < n)
        {
            if (v[r] % 2)
                r++;
            else
                break; // r存储第一个偶数
        }
        if(l < r) l = r + 1;
        else{
            swap(v[l],v[r]);
            l++;
        }
    }
}
int main()
{
    vector<int> v = {5,4,3,2,5,6,6,7};
    moveElement(v);
    for(auto &i : v) cout << i << "\t";
    cout << endl;
    return 0;
}