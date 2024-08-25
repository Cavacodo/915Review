// N-Queen
// 暴力
#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<string>> ans;
deque<string> dq;
bool check(vector<string> &board,int i,int j){
    for(auto &ch : board[i]) if(ch == 'Q') return 0;
    for(int k = 0; k < board.size(); k++){
        if(board[k][j] == 'Q') return 0;
    }
    int m = i,n = j;
    while(m > 0 && n > 0) m--,n--;
    for(m,n;m<board.size() && n < board.size();m++,n++){
        if(board[m][n] == 'Q') return 0;
    }
    m = i,n = j;
    while(n<board.size()-1 && m > 0) m--,n++;
    for(m,n; m<board.size() && n >= 0;m++,n--){
        if(board[m][n] == 'Q') return 0;
    } 
    return 1;
}
void dfs(vector<string> &board,int i){
    if(dq.size() == board.size()){
        ans.push_back(vector<string>(dq.begin(),dq.end()));
    }else{
        for(int m = i; m < board.size(); m++){
            for(int n = 0; n < board.size(); n++){
                if(check(board,m,n)){
                    board[m][n] = 'Q';
                    dq.push_back(board[m]);
                    dfs(board,m+1);
                    dq.pop_back();
                    board[m][n] = '.';
                }
            }
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> t(n,s);
        dfs(t,0);
        return ans;
    }
};

int main()
{
    
    
    return	0;
}