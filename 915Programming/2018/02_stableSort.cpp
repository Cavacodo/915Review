#include <bits/stdc++.h>
using namespace std;

typedef struct studentGrades{
    string name;
    int grades;
}sGrades;

void bubbleSort(sGrades* sv,int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(sv[j].grades < sv[j+1].grades) swap(sv[j],sv[j+1]);
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
    bubbleSort(grades,m);
    cout << endl;
    for(auto &i : grades) cout << i.name << i.grades << endl;
}

int main()
{
    print();
    return	0;
}