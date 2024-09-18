#include <bits/stdc++.h>
using namespace std;
int n;

struct Pair{
    int start,end;
};

int activityArrangement(){
    cin >> n;
    vector<Pair> schedule;
    while(n--){
        int s,e;
        cin >> s >> e;
        schedule.push_back({s,e});
    }
    sort(schedule.begin(),schedule.end(),[](const Pair& p1, const Pair& p2){
        return p1.end < p2.end;
    });
    int cnt = 0;
    int endTime = 0;
    for(int i = 0; i < schedule.size(); i++){
        if(schedule[i].start >= endTime){
            cnt++;
            endTime = schedule[i].end;
        }
    }
    return cnt;
}

int main()
{
    cout << activityArrangement() << endl;
    return	0;
}