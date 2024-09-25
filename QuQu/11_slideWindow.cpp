#include <bits/stdc++.h>
using namespace std;
// 单调栈的应用
vector<int> solve(vector<int> &v, int len)
{
    vector<int> ans;
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i < len; i++)
    {
        if (v[i] > v[dq.back()])
        {
            dq.push_back(i);
        }
    }
    ans.push_back(v[dq.back()]);
    for (int i = len; i < v.size(); i++)
    {
        while (!dq.empty() && i - dq.back() > len - 1)
            dq.pop_back();
        deque<int> tdq;
        while(!dq.empty() && v[dq.back()] > v[i]){
            tdq.push_back(dq.back());
            dq.pop_back();
        }
        dq.push_back(i);
        while(!tdq.empty()){
            dq.push_back(tdq.back());
            tdq.pop_back();
        }
        ans.push_back(v[dq.back()]);
    }
    return ans;
}

int main()
{
    vector<int> v = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> t = solve(v, 3);
    for (auto i : t)
        cout << i << endl;
    return 0;
}