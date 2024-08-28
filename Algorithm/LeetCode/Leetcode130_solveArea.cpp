// 暴力搜索
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& board,vector<vector<bool>> &used,int i,int j){
        used[i][j] = 1;
        if(i < m-1 && board[i+1][j] == 'O' && !used[i+1][j]) dfs(board,used,i+1,j);
        if(j < n-1 && board[i][j+1] == 'O' && !used[i][j+1]) dfs(board,used,i,j+1);
        if(i > 0 && board[i-1][j] == 'O' && !used[i-1][j]) dfs(board,used,i-1,j);
        if(j > 0 && board[i][j-1] == 'O' && !used[i][j-1]) dfs(board,used,i,j-1);
    }
    void dfs2(vector<vector<char>>& board,int i,int j){
        board[i][j] = 'X';
        if(i < m-1 && board[i+1][j] == 'O'){
            dfs2(board,i+1,j);
        }
        if(j < n-1 && board[i][j+1] == 'O'){
            dfs2(board,i,j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<bool> t(n,0);
        vector<vector<bool>> used;
        for(int i = 0; i < m; i++){
            used.push_back(t);
        }
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(used[i][j]) continue;
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O'){
                    dfs(board,used,i,j);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(used[i][j]) continue;
                if(board[i][j] == 'O') dfs2(board,i,j); 
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','O','X'},{'X','X','O','X'}};
    sol.solve(board);
    return	0;
}