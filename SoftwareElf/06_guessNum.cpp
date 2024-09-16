#include <bits/stdc++.h>
using namespace std;

vector<int> v;
 
int main()
{
    for(int i = 10; i < 1000; i++) v.push_back(i*i);
    for(int i = 1; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[i] - v[j] == 68){
                cout << v[j] - 100 << endl;
                break;
            }
        }
    }
    
    return	0;
}