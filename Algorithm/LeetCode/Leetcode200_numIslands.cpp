// 并查集解决dfs的一道题
// 注意Union的使用
// 只使用find的话会造成一个节点挂载到两个父节点下面的情况
// 但是在union方法中，我们把一个节点的父节点挂载到另一个节点下，避免了这种情况的出现
// 比如说“工”字型，原来的情况是1号节点挂载到2和4号下面，但是在union下，先挂载到4号上，然后下一次union时是4号节点挂载到2号下而不是1号
// 反之先挂载到2号一样
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nums;
    int res;
    int find(int i){
        return nums[i] == i ? i : find(nums[i]);
    }
    void union1(int i,int j){
        if(find(i) == find(j)) return;
        nums[find(i)] = nums[find(j)];  // i合并到j上
        res--;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m*n; i++) nums.push_back(-1);
        res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(grid[i/n][i%n] == '1'){
                res++;
                nums[i] = i;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    if(i+1 < m && grid[i+1][j] == '1'){
                        union1(i*n+j,(i+1)*n+j);
                    }
                    if(j+1 < n && grid[i][j+1] == '1'){
                        union1(i*n+j,i*n+j+1);
                    }
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution sl;
    vector<vector<char>> board = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    sl.numIslands(board);
    return	0;
}