// ────────────────────────────────────────────────────────────
// Problem : N-Queens
// Platform: LeetCode
// URL     : https://leetcode.com/problems/n-queens/description/
// Language: cpp
// Date    : 6/18/2026, 10:11:06 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n!)
// Space Complexity: O(n^2)
// Notes           : recursion
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> ans;
    void solve(int row, int n, vector<string>& board,
               vector<int>& cols,
               vector<int>& diag1,
               vector<int>& diag2) {
        // all queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
                continue;
            board[row][col] = 'Q';
            cols[col] = 1;
            diag1[row - col + n - 1] = 1;  
            diag2[row + col] = 1;          
            // move to next row
            solve(row + 1, n, board, cols, diag1, diag2);
            // backtrack
            board[row][col] = '.';
            cols[col] = 0;
            diag1[row - col + n - 1] = 0;
            diag2[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0);
        vector<int> diag1(2*n - 1, 0);
        vector<int> diag2(2*n - 1, 0);
        solve(0, n, board, cols, diag1, diag2);
        return ans;
    }
};