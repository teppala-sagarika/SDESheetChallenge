// ────────────────────────────────────────────────────────────
// Problem : number-of-islands
// Platform: LeetCode
// URL     : https://leetcode.com/problems/number-of-islands/
// Language: C++
// Date    : 7/22/2026, 11:38:27 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(m*n)
// Space Complexity: O(m*n)
// Notes           : dfs
// ────────────────────────────────────────────────────────────

class Solution {
private:
    void dfs(int r,int c,int m,int n,vector<vector<int>> &vis,vector<vector<char>>& grid){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0' ||vis[r][c]==1){
            return;
        }
        vis[r][c]=1;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            dfs(nr,nc,m,n,vis,grid);
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
                    dfs(i,j,m,n,vis,grid);
                    c++;
                }
            }
        }
        return c;
    }
};