// 自守数
#include <bits/stdc++.h>
using namespace std;

vector<long> arr;
void getSelf(){
    long n = 100000l;
    long long ns = n * n;
    for(long i = 0l; i <= n; i++){
        long long tmp = i * i;
        string s = to_string(tmp);
        string origin = to_string(i);
        if(s.substr(s.length()-origin.length(),origin.length()) == origin){
            arr.push_back(i);
        }
    }
    for(auto i : arr) cout << i << "\t";
    cout << endl;
}
int main()
{
    getSelf();
    
    return	0;
}