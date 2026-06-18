// ────────────────────────────────────────────────────────────
// Problem : Sudoku Solver
// Platform: LeetCode
// URL     : https://leetcode.com/problems/sudoku-solver/description/
// Language: cpp
// Date    : 6/18/2026, 10:13:06 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(9^81)
// Space Complexity: O(81)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool isValid(vector<vector<char>>& board,char c,int i,int j){
        for(int k=0;k<9;k++){
            if(board[i][k]==c){
                return false;
            }
            if(board[k][j]==c){
                return false;
            }
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,c,i,j)){
                            board[i][j]=c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};