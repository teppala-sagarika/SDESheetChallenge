// ────────────────────────────────────────────────────────────
// Problem : Flood Fill
// Platform: LeetCode
// URL     : https://leetcode.com/problems/flood-fill/description/
// Language: cpp
// Date    : 7/16/2026, 12:32:23 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n*m)
// Space Complexity: O(n*m)
// Notes           : dfs
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void dfs(vector<vector<int>>& image,int n,int m,int r, int c,int initColor, int newColor){
        if(r<0 || c<0 || r>=n || c>=m){
            return;
        }
        if(image[r][c]!=initColor){
            return;
        }
        image[r][c]=newColor;
        int row[]={1,-1,0,0};
        int col[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            dfs(image,n,m,r+row[i],c+col[i],initColor,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        dfs(image,n,m,sr,sc,image[sr][sc],color);
        return image;
    }
};