// ────────────────────────────────────────────────────────────
// Problem : number-of-islands
// Platform: LeetCode
// URL     : https://leetcode.com/problems/number-of-islands/
// Language: C++
// Date    : 7/22/2026, 11:58:52 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(m*n)
// Space Complexity: O(m*n)
// Notes           : bfs
// ────────────────────────────────────────────────────────────

class Solution {
private:
    void bfs(int row,int col,int m,int n,vector<vector<int>> &vis,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int delRow[] = {-1, 1, 0, 0};
            int delCol[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1' && vis[nr][nc] == 0) {
            q.push({nr, nc});
            vis[nr][nc] = 1;
            }
        }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(i,j,m,n,vis,grid);
                    c++;
                }
            }
        }
        return c;
    }
};