#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> umap;
vector<int> poker(5,0);

bool isStraight(){
    sort(poker.begin(),poker.end());
    int cnt = 1, w = 0;
    for(int i : poker) if(i == -1) w++;
    for(int i = 1; i < 5; i++){
        if(poker[i-1] + 1 == poker[i]) cnt++;
    }
    if(cnt + w >= 5) return true;
    return false;
}

int main()
{
    umap['A'] = 1;
    umap['J'] = 11;
    umap['Q'] = 12;
    umap['K'] = 13;
    umap['W'] = -1;
    for(int i = 0; i < 5; i++){
        string s;
        cin >> s;
        if(s.size() == 1){
            if(s[0] <= '9' && s[0] >= '2') poker[i] = s[0] - '0';
            else poker[i] = umap[s[0]];
        }else{
            poker[i] = 10;
        }
    }
    cout << (int)isStraight() << endl;
    return	0;
}