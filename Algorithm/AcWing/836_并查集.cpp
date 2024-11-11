#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010

int n,m;
int pa[N];
int find(int x){
     if(pa[x]!=x) pa[x]=find(pa[x]);
     return pa[x];
}
void Union(int a,int b){
    pa[find(a)] = find(b);
}

int main(){
    for(int i = 0; i < N; i++) pa[i] = i;
    cin >> n >> m;
    while(m--){
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c == 'M') Union(a,b);
        else{
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}