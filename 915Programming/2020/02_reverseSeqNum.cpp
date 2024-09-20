#include <bits/stdc++.h>
using namespace std;
int n;
struct Pair{
    int x,y;
};

vector<Pair> v;

int reverseNum(int num){
    string s = to_string(num);
    for(int i = 0; i < s.size()/2; i++){
        swap(s[i],s[s.size()-1-i]);
    }
    return stoi(s);
}

void printPairs(){
    for(int i = 0; i < n; i++){
        int rx = reverseNum(v[i].x);
        int ry = reverseNum(v[i].y);
        if(rx + ry == reverseNum(v[i].x+v[i].y)) cout << v[i].x << "\t" << v[i].y << endl;
        else cout << "none" << endl;
    }
}
int main()
{
    cin >> n;
    int m = n;
    while(m--){
        int a,b;
        cin >> a >> b;
        Pair p = {a,b};
        v.push_back(p);
    }
    printPairs();
    return	0;
}