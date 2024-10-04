#include <bits/stdc++.h>
#define size 100
using namespace std;

int UFSet[size];
int rnk[size];
void Init(int pa[]){
    for(int i=0;i<size;i++) {
        pa[i] = i;
        rnk[i] = 1;
    }
}
//把返回最根节点的父亲也就是找到x的最祖先
int find(int pa[],int x){
    return pa[x] == x ? x : find(pa,pa[x]);
}
//合并两个最祖先的，2链接到1下
void Union(int pa[],int root1,int root2){
    pa[find(pa,root1)] = find(pa,root2);
}
//优化后的find函数，使用路径压缩，将所有的子节点挂在父亲下面
//pa[x] = find(pa,x)就是在执行挂载
int find_opt(int pa[],int x){
    return pa[x] == x ? x : pa[x] = find(pa,x);
}
//按秩合并，把高度低的树合并到高度高的树下面
//不能做路径压缩，不然树型被毁了
void Union_opt(int pa[],int x,int y){
    //这里找到的是最祖先的，pa数组存储的是最直接的父亲
    //把小的合并到大的上
    int root1 = find(pa,x);
    int root2 = find(pa,y);
    if(root1 == root2) return;
    if(rnk[x] > rnk[y]){
        pa[y] = x;
    }else if(rnk[x] < rnk[y]){
        pa[x] = y;
    }else{
        rnk[x]++;
    }
}
int main()
{
    
    
    return	0;
}