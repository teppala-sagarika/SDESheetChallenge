// ────────────────────────────────────────────────────────────
// Problem : Flood Fill
// Platform: LeetCode
// URL     : https://leetcode.com/problems/flood-fill/description/
// Language: cpp
// Date    : 7/16/2026, 12:57:50 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N × M)
// Space Complexity: O(N × M)
// Notes           : bfs
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        
        int n=image.size();
        int m=image[0].size();
        int initColor=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;

            q.pop();

            int row[]={1,-1,0,0};
            int col[]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initColor){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};