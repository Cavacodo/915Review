#include <bits/stdc++.h>
using namespace std;

typedef struct studentGrades{
    string name;
    int grades;
}sGrades;

void stableSort(sGrades* sv,int n){
    for(int i = 0; i < n-1; i++){
        int max = sv[i].grades;
        for(int j = i+1; j < n; j++){
            if(sv[j].grades > max){
                max = sv[j].grades;
                swap(sv[i],sv[j]);
            }
        }
    }
}

void print(){
    int n;
    cin >> n;
    int m = n;
    sGrades grades[n];
    int cnt = 0;
    while(n--){
        string s;
        int score;
        cin >> s >> score;
        grades[cnt++] = {s,score};
    }
    stableSort(grades,m);
    cout << endl;
    for(auto &i : grades) cout << i.name << i.grades << endl;
}

int main()
{
    print();
    return	0;
}