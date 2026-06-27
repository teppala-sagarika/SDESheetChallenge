// ────────────────────────────────────────────────────────────
// Problem : Rotting Oranges
// Platform: LeetCode
// URL     : https://leetcode.com/problems/rotting-oranges/submissions/2048032488/
// Language: cpp
// Date    : 6/27/2026, 9:54:24 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N × M)
// Space Complexity: O(N × M)
// Notes           : BFS
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); //row col tym 
                }
                if(grid[i][j]==1){
                    cFresh++;
                }
            }
        }
        int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newRow=r+delRow[i];
                int newCol=c+delCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 ){
                    q.push({{newRow,newCol},t+1});
                    grid[newRow][newCol] = 2;
                    cFresh--;
                }
            }
        }
        if(!cFresh){
            return tm;
        }
        return -1;
    }
};