#include <bits/stdc++.h>
using namespace std;

struct Pair{
    int x,y;
};
vector<Pair> v;
void BiggestRectangle(){
    int n = v.size();
    int right = INT_MIN, top = INT_MIN, bottom = INT_MAX, left = INT_MAX;
    for(int i = 0; i < v.size(); i++){
        right = max(right,v[i].x);
        left = min(left,v[i].x);
        top = max(top,v[i].y);
        bottom = min(bottom,v[i].y);
    }
    cout << "left_bottom:" << left << ',' << bottom << endl;
    cout << "right_top:" << right << ',' << top << endl;
}

int main()
{
    while(1){
        int x,y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        Pair p = {x,y};
        v.push_back(p);
    }  
    BiggestRectangle();
    return	0;
}