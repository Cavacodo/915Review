#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<char,int> umap;
struct Grades{
    int score;
    char c;
};

vector<Grades> g;

int main()
{
    umap['b'] = 0;
    umap['r'] = 0;
    umap['g'] = 0;
    umap['p'] = 0;
    cin >> n;
    int m = n;
    while(m--){
        int score;
        char color;
        cin >> score >> color;
        umap[color]++;
        Grades grades = {score,color};
        g.push_back(grades);
    }
    sort(g.begin(),g.end(),[](Grades g1,Grades g2){
        return g1.score > g2.score;
    });
    unordered_map<char,string> cmap;
    cmap['r'] = "red";
    cmap['g'] = "green";
    cmap['b'] = "blue";
    cmap['p'] = "purple";
    for(const auto &pair : umap){
        cout << cmap[pair.first] << '\t' << pair.second << endl;
    }
    for(auto &i : g){
        cout << i.score << '\t' << cmap[i.c] << endl;
    }
    return	0;
}